program attenaution
use, intrinsic :: iso_fortran_env, only: real32, real64
implicit none

real(kind=real64) :: sigma1, sigma2
real(kind=real64) :: thick1, thick2
real(kind=real64) :: intensity0, intensity

integer :: iounit
logical :: ioexists
character(len=*), parameter :: inputdata = "data.txt"

inquire(file=inputdata, exist=ioexists)
if (.not. ioexists) then
    write(*,*) "Non-existing input file"
    return
end if

open(newunit=iounit, file=inputdata, status="old", action="read")
read(iounit, *) sigma1
read(iounit, *) sigma2
read(iounit, *) thick1
read(iounit, *) thick2
read(iounit, *) intensity0
close(iounit)

intensity = intensity0 * exp(- (sigma1*thick1 + sigma2*thick2))

!write(*,*) sigma1, sigma2, thick1, thick2, intensity0
write(*,*) intensity

end program attenaution