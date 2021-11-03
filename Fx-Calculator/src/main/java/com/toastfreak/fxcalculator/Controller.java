package com.toastfreak.fxcalculator;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

public class Controller {

    public Button one;
    public Button two;
    public Button three;
    public Button four;
    public Button five;
    public Button six;
    public Button seven;
    public Button eight;
    public Button nine;
    public Button zero;
    public Button decimal;
    public TextArea input;

    public double num1 = 0;
    public double num2 = 0;

    public boolean sum, difference, product, quotient;

    public void add_pressed(ActionEvent e) {
        if (input.getText() != "") {
            num1 = Double.parseDouble(input.getText());
            input.clear();
            sum = true;
        }
    }

    public void subtract_pressed(ActionEvent e) {
        if (input.getText() != "") {
            num1 = Double.parseDouble(input.getText());
            input.clear();
            difference = true;
        }
    }

    public void multiply_pressed(ActionEvent e) {
        if (input.getText() != "") {
            num1 = Double.parseDouble(input.getText());
            input.clear();
            product = true;
        }
    }

    public void divide_pressed(ActionEvent e) {
        if (input.getText() != "") {
            num1 = Double.parseDouble(input.getText());
            input.clear();
            quotient = true;
        }
    }

    public void equals_pressed(ActionEvent e) {
        if (input.getText() != "") {
            num2 = Double.parseDouble(input.getText());
            input.clear();
            if (sum == true) {
                input.appendText(String.valueOf(num1 + num2));
                sum = false;
            } else if (difference == true) {
                input.appendText(String.valueOf(num1 - num2));
                difference = false;
            } else if (product == true) {
                input.appendText(String.valueOf(num1 * num2));
                product = false;
            } else if (quotient == true) {
                input.appendText(String.valueOf(num1 / num2));
                quotient = false;
            }
        }
    }

    public void percentage_pressed(ActionEvent e) {
        if(input.getText()!=""){
            if (num1 == 0 && input.getText() != "") {
                num1 = (Double.parseDouble(input.getText()) / 100);
                input.clear();
                input.appendText(String.valueOf(num1));
            } else if (num1 > 0 && input.getText() != "" || num1 < 0 && input.getText() != "") {
                num2 = (Double.parseDouble(input.getText()) / 100);
                input.clear();
                input.appendText(String.valueOf(num2));
            }
        }
    }

    public void clear_pressed(ActionEvent e) {
        if (input.getText() != "") {
            input.clear();
            num1 = 0;
            num2 = 0;
            sum = false;
            difference = false;
            product = false;
            quotient = false;
        }
    }

    public void positive_negative_pressed(ActionEvent e) {
        if (num1 == 0 && input.getText() != "") {
            num1 = (Double.parseDouble(input.getText()) * -1);
            input.clear();
            input.appendText(String.valueOf(num1));
        } else if (num1 > 0 && input.getText() != "" || num1 < 0 && input.getText() != "") {
            num2 = (Double.parseDouble(input.getText()) * -1);
            input.clear();
            input.appendText(String.valueOf(num2));
        }
    }

    public void button_pressed(ActionEvent e) {
        //adding the functionality to the buttons 0-9 and .
        if (e.getSource() == one) {
            input.appendText("1");
        } else if (e.getSource() == two) {
            input.appendText("2");
        } else if (e.getSource() == three) {
            input.appendText("3");
        } else if (e.getSource() == four) {
            input.appendText("4");
        } else if (e.getSource() == five) {
            input.appendText("5");
        } else if (e.getSource() == six) {
            input.appendText("6");
        } else if (e.getSource() == seven) {
            input.appendText("7");
        } else if (e.getSource() == eight) {
            input.appendText("8");
        } else if (e.getSource() == nine) {
            input.appendText("9");
        } else if (e.getSource() == zero && input.getText() != "" || e.getSource() == zero && num1 > 0) {
            input.appendText("0");
        } else if (e.getSource() == decimal && !input.getText().contains(".")) {
            input.appendText(".");
        }
    }
}