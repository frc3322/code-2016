$(document).ready(function() {

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
	getSpeed();
	getDirection();
	getLoadSpeed();
	getShootSpeed();
}, 20);
});