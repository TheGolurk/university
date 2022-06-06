package calculadora;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class Calcu extends javax.swing.JFrame {
    
    ScriptEngineManager sem = new ScriptEngineManager();
    ScriptEngine se = sem.getEngineByName("JavaScript");
    
    public Calcu() {
        initComponents();
        setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        PanelResul = new javax.swing.JPanel();
        txtOperacion = new javax.swing.JLabel();
        txtResultado = new javax.swing.JLabel();
        PanelDatos = new javax.swing.JPanel();
        BtoBorrar = new javax.swing.JButton();
        BtoPotencia = new javax.swing.JButton();
        BtoPorcentaje = new javax.swing.JButton();
        BtoDividir = new javax.swing.JButton();
        BtoMulti = new javax.swing.JButton();
        BtoResta = new javax.swing.JButton();
        BtoSuma = new javax.swing.JButton();
        BtoRes = new javax.swing.JButton();
        BtoPunto = new javax.swing.JButton();
        Bto7 = new javax.swing.JButton();
        Bto8 = new javax.swing.JButton();
        Bto9 = new javax.swing.JButton();
        Bto4 = new javax.swing.JButton();
        Bto5 = new javax.swing.JButton();
        Bto6 = new javax.swing.JButton();
        Bto1 = new javax.swing.JButton();
        Bto2 = new javax.swing.JButton();
        Bto3 = new javax.swing.JButton();
        Bto0 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);
        setType(java.awt.Window.Type.UTILITY);

        PanelResul.setBackground(new java.awt.Color(33, 43, 65));

        txtOperacion.setFont(new java.awt.Font("Segoe UI Semibold", 1, 18)); // NOI18N
        txtOperacion.setForeground(new java.awt.Color(13, 179, 135));
        txtOperacion.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);

        txtResultado.setFont(new java.awt.Font("Segoe UI Black", 1, 36)); // NOI18N
        txtResultado.setForeground(new java.awt.Color(13, 179, 135));
        txtResultado.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);


        PanelDatos.setBackground(new java.awt.Color(45, 56, 80));

        BtoBorrar.setBackground(new java.awt.Color(46, 57, 81));
        BtoBorrar.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoBorrar.setForeground(new java.awt.Color(13, 179, 135));
        BtoBorrar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoBorrar.setText("C");
        BtoBorrar.setBorder(null);
        BtoBorrar.setBorderPainted(false);
        BtoBorrar.setContentAreaFilled(false);
        BtoBorrar.setFocusPainted(false);
        BtoBorrar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoBorrar.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoBorrar.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoBorrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoBorrarActionPerformed(evt);
            }
        });

        BtoPotencia.setBackground(new java.awt.Color(46, 57, 81));
        BtoPotencia.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoPotencia.setForeground(new java.awt.Color(13, 179, 135));
        BtoPotencia.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoPotencia.setText("^");
        BtoPotencia.setBorder(null);
        BtoPotencia.setBorderPainted(false);
        BtoPotencia.setContentAreaFilled(false);
        BtoPotencia.setFocusPainted(false);
        BtoPotencia.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoPotencia.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoPotencia.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoPotencia.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoPotenciaActionPerformed(evt);
            }
        });

        BtoPorcentaje.setBackground(new java.awt.Color(46, 57, 81));
        BtoPorcentaje.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoPorcentaje.setForeground(new java.awt.Color(13, 179, 135));
        BtoPorcentaje.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoPorcentaje.setText("%");
        BtoPorcentaje.setBorder(null);
        BtoPorcentaje.setBorderPainted(false);
        BtoPorcentaje.setContentAreaFilled(false);
        BtoPorcentaje.setFocusPainted(false);
        BtoPorcentaje.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoPorcentaje.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoPorcentaje.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoPorcentaje.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoPorcentajeActionPerformed(evt);
            }
        });

        BtoDividir.setBackground(new java.awt.Color(46, 57, 81));
        BtoDividir.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoDividir.setForeground(new java.awt.Color(13, 179, 135));
        BtoDividir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoDividir.setText("÷");
        BtoDividir.setBorder(null);
        BtoDividir.setBorderPainted(false);
        BtoDividir.setContentAreaFilled(false);
        BtoDividir.setFocusPainted(false);
        BtoDividir.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoDividir.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoDividir.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoDividir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoDividirActionPerformed(evt);
            }
        });

        BtoMulti.setBackground(new java.awt.Color(46, 57, 81));
        BtoMulti.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoMulti.setForeground(new java.awt.Color(13, 179, 135));
        BtoMulti.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoMulti.setText("X");
        BtoMulti.setBorder(null);
        BtoMulti.setBorderPainted(false);
        BtoMulti.setContentAreaFilled(false);
        BtoMulti.setFocusPainted(false);
        BtoMulti.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoMulti.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoMulti.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoMulti.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoMultiActionPerformed(evt);
            }
        });

        BtoResta.setBackground(new java.awt.Color(46, 57, 81));
        BtoResta.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoResta.setForeground(new java.awt.Color(13, 179, 135));
        BtoResta.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoResta.setText("-");
        BtoResta.setBorder(null);
        BtoResta.setBorderPainted(false);
        BtoResta.setContentAreaFilled(false);
        BtoResta.setFocusPainted(false);
        BtoResta.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoResta.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoResta.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoResta.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoRestaActionPerformed(evt);
            }
        });

        BtoSuma.setBackground(new java.awt.Color(46, 57, 81));
        BtoSuma.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoSuma.setForeground(new java.awt.Color(13, 179, 135));
        BtoSuma.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoSuma.setText("+");
        BtoSuma.setBorder(null);
        BtoSuma.setBorderPainted(false);
        BtoSuma.setContentAreaFilled(false);
        BtoSuma.setFocusPainted(false);
        BtoSuma.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoSuma.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoSuma.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton1press.png"))); // NOI18N
        BtoSuma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoSumaActionPerformed(evt);
            }
        });

        BtoRes.setBackground(new java.awt.Color(46, 57, 81));
        BtoRes.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoRes.setForeground(new java.awt.Color(33, 43, 65));
        BtoRes.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton2.png"))); // NOI18N
        BtoRes.setText("=");
        BtoRes.setBorder(null);
        BtoRes.setBorderPainted(false);
        BtoRes.setContentAreaFilled(false);
        BtoRes.setFocusPainted(false);
        BtoRes.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoRes.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton2.png"))); // NOI18N
        BtoRes.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton2press.png"))); // NOI18N
        BtoRes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoResActionPerformed(evt);
            }
        });

        BtoPunto.setBackground(new java.awt.Color(46, 57, 81));
        BtoPunto.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        BtoPunto.setForeground(new java.awt.Color(150, 168, 160));
        BtoPunto.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        BtoPunto.setText(".");
        BtoPunto.setBorder(null);
        BtoPunto.setBorderPainted(false);
        BtoPunto.setContentAreaFilled(false);
        BtoPunto.setFocusPainted(false);
        BtoPunto.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        BtoPunto.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        BtoPunto.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        BtoPunto.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BtoPuntoActionPerformed(evt);
            }
        });

        Bto7.setBackground(new java.awt.Color(46, 57, 81));
        Bto7.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto7.setForeground(new java.awt.Color(150, 168, 160));
        Bto7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto7.setText("7");
        Bto7.setBorder(null);
        Bto7.setBorderPainted(false);
        Bto7.setContentAreaFilled(false);
        Bto7.setFocusPainted(false);
        Bto7.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto7.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto7.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto7.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto7ActionPerformed(evt);
            }
        });

        Bto8.setBackground(new java.awt.Color(46, 57, 81));
        Bto8.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto8.setForeground(new java.awt.Color(150, 168, 160));
        Bto8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto8.setText("8");
        Bto8.setBorder(null);
        Bto8.setBorderPainted(false);
        Bto8.setContentAreaFilled(false);
        Bto8.setFocusPainted(false);
        Bto8.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto8.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto8.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto8ActionPerformed(evt);
            }
        });

        Bto9.setBackground(new java.awt.Color(46, 57, 81));
        Bto9.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto9.setForeground(new java.awt.Color(150, 168, 160));
        Bto9.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto9.setText("9");
        Bto9.setBorder(null);
        Bto9.setBorderPainted(false);
        Bto9.setContentAreaFilled(false);
        Bto9.setFocusPainted(false);
        Bto9.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto9.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto9.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto9ActionPerformed(evt);
            }
        });

        Bto4.setBackground(new java.awt.Color(46, 57, 81));
        Bto4.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto4.setForeground(new java.awt.Color(150, 168, 160));
        Bto4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto4.setText("4");
        Bto4.setBorder(null);
        Bto4.setBorderPainted(false);
        Bto4.setContentAreaFilled(false);
        Bto4.setFocusPainted(false);
        Bto4.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto4.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto4.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto4ActionPerformed(evt);
            }
        });

        Bto5.setBackground(new java.awt.Color(46, 57, 81));
        Bto5.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto5.setForeground(new java.awt.Color(150, 168, 160));
        Bto5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto5.setText("5");
        Bto5.setBorder(null);
        Bto5.setBorderPainted(false);
        Bto5.setContentAreaFilled(false);
        Bto5.setFocusPainted(false);
        Bto5.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto5.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto5.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto5ActionPerformed(evt);
            }
        });

        Bto6.setBackground(new java.awt.Color(46, 57, 81));
        Bto6.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto6.setForeground(new java.awt.Color(150, 168, 160));
        Bto6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto6.setText("6");
        Bto6.setBorder(null);
        Bto6.setBorderPainted(false);
        Bto6.setContentAreaFilled(false);
        Bto6.setFocusPainted(false);
        Bto6.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto6.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto6.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto6ActionPerformed(evt);
            }
        });

        Bto1.setBackground(new java.awt.Color(46, 57, 81));
        Bto1.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto1.setForeground(new java.awt.Color(150, 168, 160));
        Bto1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto1.setText("1");
        Bto1.setBorder(null);
        Bto1.setBorderPainted(false);
        Bto1.setContentAreaFilled(false);
        Bto1.setFocusPainted(false);
        Bto1.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto1.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto1.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto1ActionPerformed(evt);
            }
        });

        Bto2.setBackground(new java.awt.Color(46, 57, 81));
        Bto2.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto2.setForeground(new java.awt.Color(150, 168, 160));
        Bto2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto2.setText("2");
        Bto2.setBorder(null);
        Bto2.setBorderPainted(false);
        Bto2.setContentAreaFilled(false);
        Bto2.setFocusPainted(false);
        Bto2.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto2.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto2.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto2ActionPerformed(evt);
            }
        });

        Bto3.setBackground(new java.awt.Color(46, 57, 81));
        Bto3.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto3.setForeground(new java.awt.Color(150, 168, 160));
        Bto3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto3.setText("3");
        Bto3.setBorder(null);
        Bto3.setBorderPainted(false);
        Bto3.setContentAreaFilled(false);
        Bto3.setFocusPainted(false);
        Bto3.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto3.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto3.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto3ActionPerformed(evt);
            }
        });

        Bto0.setBackground(new java.awt.Color(46, 57, 81));
        Bto0.setFont(new java.awt.Font("Segoe UI Semibold", 1, 24)); // NOI18N
        Bto0.setForeground(new java.awt.Color(150, 168, 160));
        Bto0.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto0.setText("0");
        Bto0.setBorder(null);
        Bto0.setBorderPainted(false);
        Bto0.setContentAreaFilled(false);
        Bto0.setFocusPainted(false);
        Bto0.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        Bto0.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/Boton.png"))); // NOI18N
        Bto0.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/boton3.png"))); // NOI18N
        Bto0.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Bto0ActionPerformed(evt);
            }
        });


        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void BtoPuntoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoPuntoActionPerformed
        addNumber(".");
    }//GEN-LAST:event_BtoPuntoActionPerformed

    private void Bto7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto7ActionPerformed
        addNumber("7");
    }//GEN-LAST:event_Bto7ActionPerformed

    private void Bto8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto8ActionPerformed
        addNumber("8");
    }//GEN-LAST:event_Bto8ActionPerformed

    private void Bto9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto9ActionPerformed
        addNumber("9");
    }//GEN-LAST:event_Bto9ActionPerformed

    private void Bto4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto4ActionPerformed
        addNumber("4");
    }//GEN-LAST:event_Bto4ActionPerformed

    private void Bto5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto5ActionPerformed
        addNumber("5");
    }//GEN-LAST:event_Bto5ActionPerformed

    private void Bto6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto6ActionPerformed
        addNumber("6");
    }//GEN-LAST:event_Bto6ActionPerformed

    private void Bto1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto1ActionPerformed
        addNumber("1");
    }//GEN-LAST:event_Bto1ActionPerformed

    private void Bto2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto2ActionPerformed
        addNumber("2");
    }//GEN-LAST:event_Bto2ActionPerformed

    private void Bto3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto3ActionPerformed
        addNumber("3");
    }//GEN-LAST:event_Bto3ActionPerformed

    private void Bto0ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Bto0ActionPerformed
        addNumber("0");
    }//GEN-LAST:event_Bto0ActionPerformed

    private void BtoBorrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoBorrarActionPerformed
        txtOperacion.setText("");
        txtResultado.setText("");
    }//GEN-LAST:event_BtoBorrarActionPerformed

    private void BtoPotenciaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoPotenciaActionPerformed
        addNumber("^");
    }//GEN-LAST:event_BtoPotenciaActionPerformed

    private void BtoPorcentajeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoPorcentajeActionPerformed
        addNumber("%");
    }//GEN-LAST:event_BtoPorcentajeActionPerformed

    private void BtoDividirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoDividirActionPerformed
        addNumber("/");
    }//GEN-LAST:event_BtoDividirActionPerformed

    private void BtoMultiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoMultiActionPerformed
        addNumber("*");
    }//GEN-LAST:event_BtoMultiActionPerformed

    private void BtoRestaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoRestaActionPerformed
        addNumber("-");
    }//GEN-LAST:event_BtoRestaActionPerformed

    private void BtoSumaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoSumaActionPerformed
        addNumber("+");
    }//GEN-LAST:event_BtoSumaActionPerformed

    private void BtoResActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtoResActionPerformed
        try {
            String res = se.eval(txtOperacion.getText()).toString();
            txtResultado.getText();
            System.out.println("hola"+res);
            System.out.println(""+txtResultado);
        } catch (ScriptException ex) {
            System.out.println("Problemas");
        }
    }//GEN-LAST:event_BtoResActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Calcu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Calcu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Calcu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Calcu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Calcu().setVisible(true);
            }
        });
    }
    public void addNumber(String digito){
        txtOperacion.setText(txtOperacion.getText()+digito);
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Bto0;
    private javax.swing.JButton Bto1;
    private javax.swing.JButton Bto2;
    private javax.swing.JButton Bto3;
    private javax.swing.JButton Bto4;
    private javax.swing.JButton Bto5;
    private javax.swing.JButton Bto6;
    private javax.swing.JButton Bto7;
    private javax.swing.JButton Bto8;
    private javax.swing.JButton Bto9;
    private javax.swing.JButton BtoBorrar;
    private javax.swing.JButton BtoDividir;
    private javax.swing.JButton BtoMulti;
    private javax.swing.JButton BtoPorcentaje;
    private javax.swing.JButton BtoPotencia;
    private javax.swing.JButton BtoPunto;
    private javax.swing.JButton BtoRes;
    private javax.swing.JButton BtoResta;
    private javax.swing.JButton BtoSuma;
    private javax.swing.JPanel PanelDatos;
    private javax.swing.JPanel PanelResul;
    private javax.swing.JLabel txtOperacion;
    private javax.swing.JLabel txtResultado;
    // End of variables declaration//GEN-END:variables
}
