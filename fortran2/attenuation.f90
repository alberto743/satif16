module geometry
    use, intrinsic :: iso_fortran_env, only: real32, real64
    implicit none

    real(kind=real64) :: thick1, thick2
contains
    subroutine load_geometry(iounit)
        integer, intent(in) :: iounit

        read(iounit, *) thick1
        read(iounit, *) thick2
    end subroutine load_geometry
end module geometry


module materials
    use, intrinsic :: iso_fortran_env, only: real32, real64
    implicit none

    real(kind=real64) :: sigma1, sigma2
contains
    subroutine load_materials(iounit)
        integer, intent(in) :: iounit

        read(iounit, *) sigma1
        read(iounit, *) sigma2
    end subroutine load_materials
end module materials


module source
    use, intrinsic :: iso_fortran_env, only: real32, real64
    implicit none

    real(kind=real64) :: intensity0
contains
    subroutine load_source(iounit)
        integer, intent(in) :: iounit

        read(iounit, *) intensity0
    end subroutine load_source
end module source


module solution
    use, intrinsic :: iso_fortran_env, only: real32, real64
    use geometry
    use materials
    use source
    implicit none

    real(kind=real64) :: intensity
contains
    subroutine solver()
        intensity = intensity0 * exp(- (sigma1*thick1 + sigma2*thick2))
    end subroutine solver
end module solution


program attenaution
    use, intrinsic :: iso_fortran_env, only: real32, real64
    use geometry
    use materials
    use source
    use solution
    implicit none

    integer :: iounit
    logical :: ioexists
    character(len=*), parameter :: inputdata = "data.txt"

    inquire(file=inputdata, exist=ioexists)
    if (.not. ioexists) then
        write(*,*) "Non-existing input file"
        return
    end if

    open(newunit=iounit, file=inputdata, status="old", action="read")
    call load_geometry(iounit)
    call load_materials(iounit)
    call load_source(iounit)
    close(iounit)

    call solver()

    !write(*,*) sigma1, sigma2, thick1, thick2, intensity0
    write(*,*) intensity
end program attenaution
