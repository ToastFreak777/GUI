module com.toastfreak.fxcalculator {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;
    requires javafx.graphics;

    opens com.toastfreak.fxcalculator to javafx.fxml;
    exports com.toastfreak.fxcalculator;
}