$(document).ready(function() {

$('#intake-pid-on').click(function() {
	NetworkTables.setValue('/SmartDashboard/useIntake', true, false);
});

$('#intake-pid-off').click(function() {
	NetworkTables.setValue('/SmartDashboard/useIntake', false, false);
});

$('#auton-none').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 0, 0)
	$('#auton-mode').val("None")
    });

$('#auton-lowbar').click(function () {
	NetworkTables.setValue('/SmartDashboard/autonMode', 1, 0)
	$('#auton-mode').val("Low Bar")
    });
    
function getEncoders()
{
	$('#encoder-1').val(NetworkTables.getValue('/SmartDashboard/encoder1', 0.0))
	$('#encoder-2').val(NetworkTables.getValue('/SmartDashboard/encoder2', 0.0))
}

function getAngle()
{
	$('#arm-angle').val(NetworkTables.getValue('/SmartDashboard/armangle', 0.0))
}

function getGear()
{
	document.getElementById("robot-gear").style.fontSize = "24px"
	var v = NetworkTables.getValue('/SmartDashboard/highGear', false)
	
	if (v)
		document.getElementById("robot-gear").style.color = "green"
	else
		document.getElementById("robot-gear").style.color = "red"
	$('#robot-gear').val((v ? "HIGH GEAR" : "LOW GEAR"))
}

function getSpeed()
{
	var left = NetworkTables.getValue('/SmartDashboard/talon0', 0.0)
	var right = NetworkTables.getValue('/SmartDashboard/talon1', 0.0)
	$('#speed').val((left + right) / 2.);
}

function getDirection()
{
	var left = NetworkTables.getValue('/SmartDashboard/talon0', 0.0)
	var right = NetworkTables.getValue('/SmartDashboard/talon1', 0.0)
	
	if ((left == 0.0) && (right == 0.0))
	{
		$('#direction').val("Still ")
		return
	}
	else if ((left > 0.0) && (right > 0.0))
		$('#direction').val("Forward ")
	else if ((left < 0.0) && (right < 0.0))
		$('#direction').val("Backward ")
		
	if (Math.abs((left - right)/(left + right)) < .10)
		$('#direction').val($('#direction').val() + "Straight")
	else if (((left - right)/(left + right)) < .30)
		$('#direction').val($('#direction').val() + "Slightly Left");
	else if (((left - right)/(left + right)) >= .30)
		$('#direction').val($('#direction').val() + "Left");
	else if (((right - left)/(left + right)) < .30)
		$('#direction').val($('#direction').val() + "Slightly Right");
	else if (((right - left)/(left + right)) >= .30)
		$('#direction').val($('#direction').val() + "Right");
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
	getSpeed();
	getDirection();
	getLoadSpeed();
	getShootSpeed();
	getAngle();
	getEncoders();
}, 50);
});