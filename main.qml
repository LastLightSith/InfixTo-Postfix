import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.VirtualKeyboard 2.3
import QtQuick.Controls 2.3
import Smit.Is.Cool 1.0

ApplicationWindow {
	id: window
	visible: true
	height: 640
	width: 600
	title: qsTr("InfixManipulator")

	InfixToPostfix{id:c_interface }

	TextField {
		id: infixIP
		placeholderText: qsTr("Enter Infix exprestion here")
		width:parent.width-20
		anchors.top: parent.top
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.topMargin: 30
		selectByMouse: true
	}

	Button {
		id: evaluate
		anchors.top:infixIP.bottom
		anchors.topMargin: 20
		anchors.left:parent.left
		anchors.leftMargin: 10
		text: qsTr("Evaluate")
		onClicked: {
			postfixOP.text = c_interface.toPostfix(infixIP.text);
			ans.text = c_interface.toAns(postfixOP.text)
		}
	}


	TextField {
		id: postfixOP
		width: parent.width-20
		anchors.top: evaluate.bottom
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.topMargin: 30
		activeFocusOnPress: false
	}

	Button {
		id: copyPostfix
		anchors.top:postfixOP.bottom
		anchors.topMargin: 20
		anchors.left:parent.left
		anchors.leftMargin: 10
		text: qsTr("Copy Postfix")

		onClicked: c_interface.copyToClipBoard(postfixOP.text)

	}

	TextField {
		id: ans
		width: parent.width-20
		anchors.top: copyPostfix.bottom
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.topMargin: 30
		activeFocusOnPress: false
	}

	Button {
		id: copyAns
		anchors.top:ans.bottom
		anchors.topMargin: 20
		anchors.left:parent.left
		anchors.leftMargin: 10
		text: qsTr("Copy Answer")
		onClicked: c_interface.copyToClipBoard(ans.text)
	}

//	on X11 and Windows
	InputPanel {
		id: inputPanel
		z: 99
		x: -8
		y: 634
		width: window.width
		active:true

		states: State {
			name: "visible"
			when: inputPanel.active
			PropertyChanges {
				target: inputPanel
				y: window.height - inputPanel.height
			}
		}
		transitions: Transition {
			from: ""
			to: "visible"
			reversible: true
			ParallelAnimation {
				NumberAnimation {
					properties: "y"
					duration: 250
					easing.type: Easing.InOutQuad
				}
			}
		}
	}
}
