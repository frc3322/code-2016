$(document).ready(function() {
/* Start of auton; There is something wrong here, I just know it! */
$('#auton-1').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 1, 0)
	$('#auton-mode').val("Portcullis")
    });

$('#auton-2').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 2, 0)
	$('#auton-mode').val("Chivel de Frise")
    });

$('#auton-3').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 3, 0)
	$('#auton-mode').val("Rough Terrain")
    });

$('#auton-4').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 4, 0)
	$('#auton-mode').val("Moat")
    });

$('#auton-5').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 5, 0)
	$('#auton-mode').val("Low Bar Simple")
    });

$('#auton-6').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 6, 0)
	$('#auton-mode').val("Low Bar Shot")
    });

$('#auton-7').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 7, 0)
	$('#auton-mode').val("Do Nothing")
    });

$('#auton-8').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 8, 0)
	$('#auton-mode').val("Reach")
    });
/* End of auton. I definitely need to glorify the code a bit more */
function getAngle()
{
	$('#arm-angle').val(NetworkTables.getValue('/SmartDashboard/armangle', 0.0))
}

function getGyro()
{
	var angle = NetworkTables.getValue('/SmartDashboard/armangle', 0)
	$("#needle").css("-webkit-transform", "rotate("+angle+"deg)");
	while (angle < 0)
		angle += 360;
	$("#gyro-angle").val(angle % 270);
}

function getFaults()
{
	if (NetworkTables.getValue('/SmartDashboard/DriveSRX1 fault', false)) { $('#faults-1').val("Drive SRX 1"); } else { $('#faults-1').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/DriveSRX2 fault', false)) { $('#faults-2').val("Drive SRX 2"); } else { $('#faults-2').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/DriveSRX3 fault', false)) { $('#faults-3').val("Drive SRX 3"); } else { $('#faults-3').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/DriveSRX4 fault', false)) { $('#faults-4').val("Drive SRX 4"); } else { $('#faults-4').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/IntakeRotateTalon1 fault', false)) { $('#faults-5').val("Intake Rotate Talon 1"); } else { $('#faults-5').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/IntakeRotateTalon2 fault', false)) { $('#faults-6').val("Intake Rotate Talon 2"); } else { $('#faults-6').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/IntakeSpinTalon1 fault', false)) { $('#faults-7').val("Intake Spin Talon 1"); } else { $('#faults-7').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/IntakeSpinTalon2 fault', false)) { $('#faults-8').val("Intake Spin Talon 2"); } else { $('#faults-8').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/CatA1 fault', false)) { $('#faults-9').val("Category A 1"); } else { $('#faults-9').val(""); }
	if (NetworkTables.getValue('/SmartDashboard/CatA2 fault', false)) { $('#faults-10').val("Category A 2"); } else { $('#faults-10').val(""); }
}

function getGear()
{
	var v = NetworkTables.getValue('/SmartDashboard/highGear', false)
	
	if (v)
		document.getElementById("robot-gear").style.color = "green"
	else
		document.getElementById("robot-gear").style.color = "red"
	$('#robot-gear').val((v ? "HIGH GEAR" : "LOW GEAR"))
}

function getLoadSpeed()
{
	$('#load-speed').val(NetworkTables.getValue('/SmartDashboard/loadSpeed',0.0))
}

function getShootSpeed()
{
	$('#shoot-speed').val(NetworkTables.getValue('/SmartDashboard/shootSpeed',0.0))
}

setInterval(function() {
	getGear();
	getGyro();
	getLoadSpeed();
	getShootSpeed();
	getAngle();
	getFaults();
}, 50);
});