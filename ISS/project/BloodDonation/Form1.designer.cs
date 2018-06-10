namespace BloodDonation
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);

            
            
        }



        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LoginSwitchButton = new System.Windows.Forms.Button();
            this.RegisterSwitchButton = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.UsernameLoginTextBox = new System.Windows.Forms.MaskedTextBox();
            this.PasswordLoginTextBox = new System.Windows.Forms.MaskedTextBox();
            this.LoginButton = new System.Windows.Forms.Button();
            this.RegisterButton = new System.Windows.Forms.Button();
            this.VerifyPassRegisterTextBox = new System.Windows.Forms.MaskedTextBox();
            this.RegisterUsernameTextBox = new System.Windows.Forms.MaskedTextBox();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.RegisterPassTextBox = new System.Windows.Forms.MaskedTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // LoginSwitchButton
            // 
            this.LoginSwitchButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(96)))), ((int)(((byte)(85)))));
            this.LoginSwitchButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.LoginSwitchButton.FlatAppearance.BorderSize = 0;
            this.LoginSwitchButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LoginSwitchButton.Font = new System.Drawing.Font("Corbel", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LoginSwitchButton.ForeColor = System.Drawing.Color.White;
            this.LoginSwitchButton.Location = new System.Drawing.Point(188, 114);
            this.LoginSwitchButton.Margin = new System.Windows.Forms.Padding(0);
            this.LoginSwitchButton.Name = "LoginSwitchButton";
            this.LoginSwitchButton.Size = new System.Drawing.Size(279, 49);
            this.LoginSwitchButton.TabIndex = 0;
            this.LoginSwitchButton.Text = "Log In";
            this.LoginSwitchButton.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.LoginSwitchButton.UseVisualStyleBackColor = false;
            this.LoginSwitchButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // RegisterSwitchButton
            // 
            this.RegisterSwitchButton.BackColor = System.Drawing.Color.DarkGray;
            this.RegisterSwitchButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.RegisterSwitchButton.FlatAppearance.BorderSize = 0;
            this.RegisterSwitchButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RegisterSwitchButton.Font = new System.Drawing.Font("Corbel", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RegisterSwitchButton.ForeColor = System.Drawing.Color.White;
            this.RegisterSwitchButton.Location = new System.Drawing.Point(467, 114);
            this.RegisterSwitchButton.Margin = new System.Windows.Forms.Padding(0);
            this.RegisterSwitchButton.Name = "RegisterSwitchButton";
            this.RegisterSwitchButton.Size = new System.Drawing.Size(279, 49);
            this.RegisterSwitchButton.TabIndex = 1;
            this.RegisterSwitchButton.Text = "Register";
            this.RegisterSwitchButton.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.RegisterSwitchButton.UseVisualStyleBackColor = false;
            this.RegisterSwitchButton.Click += new System.EventHandler(this.RegisterButton_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(136)))), ((int)(((byte)(38)))), ((int)(((byte)(41)))));
            this.dataGridView1.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.GridColor = System.Drawing.Color.FromArgb(((int)(((byte)(199)))), ((int)(((byte)(44)))), ((int)(((byte)(44)))));
            this.dataGridView1.Location = new System.Drawing.Point(188, 164);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(557, 283);
            this.dataGridView1.TabIndex = 2;
            // 
            // UsernameLoginTextBox
            // 
            this.UsernameLoginTextBox.Font = new System.Drawing.Font("Calibri", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.UsernameLoginTextBox.Location = new System.Drawing.Point(251, 224);
            this.UsernameLoginTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.UsernameLoginTextBox.Name = "UsernameLoginTextBox";
            this.UsernameLoginTextBox.Size = new System.Drawing.Size(419, 36);
            this.UsernameLoginTextBox.TabIndex = 3;
            this.UsernameLoginTextBox.Text = "Username";
            this.UsernameLoginTextBox.Click += new System.EventHandler(this.maskedTextBox1_Click);
            // 
            // PasswordLoginTextBox
            // 
            this.PasswordLoginTextBox.Font = new System.Drawing.Font("Corbel", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PasswordLoginTextBox.Location = new System.Drawing.Point(251, 304);
            this.PasswordLoginTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.PasswordLoginTextBox.Name = "PasswordLoginTextBox";
            this.PasswordLoginTextBox.PasswordChar = '*';
            this.PasswordLoginTextBox.Size = new System.Drawing.Size(419, 36);
            this.PasswordLoginTextBox.TabIndex = 4;
            this.PasswordLoginTextBox.Text = "Password";
            this.PasswordLoginTextBox.Click += new System.EventHandler(this.maskedTextBox2_Click);
            // 
            // LoginButton
            // 
            this.LoginButton.BackColor = System.Drawing.Color.Crimson;
            this.LoginButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.LoginButton.FlatAppearance.BorderSize = 0;
            this.LoginButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LoginButton.Font = new System.Drawing.Font("Corbel", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LoginButton.ForeColor = System.Drawing.Color.White;
            this.LoginButton.Location = new System.Drawing.Point(399, 370);
            this.LoginButton.Margin = new System.Windows.Forms.Padding(0);
            this.LoginButton.Name = "LoginButton";
            this.LoginButton.Size = new System.Drawing.Size(140, 49);
            this.LoginButton.TabIndex = 5;
            this.LoginButton.Text = "Log In";
            this.LoginButton.UseVisualStyleBackColor = false;
            this.LoginButton.Click += new System.EventHandler(this.button2_Click);
            // 
            // RegisterButton
            // 
            this.RegisterButton.BackColor = System.Drawing.Color.Crimson;
            this.RegisterButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.RegisterButton.FlatAppearance.BorderSize = 0;
            this.RegisterButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RegisterButton.Font = new System.Drawing.Font("Corbel", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RegisterButton.ForeColor = System.Drawing.Color.White;
            this.RegisterButton.Location = new System.Drawing.Point(399, 370);
            this.RegisterButton.Margin = new System.Windows.Forms.Padding(0);
            this.RegisterButton.Name = "RegisterButton";
            this.RegisterButton.Size = new System.Drawing.Size(140, 49);
            this.RegisterButton.TabIndex = 9;
            this.RegisterButton.Text = "Regsiter";
            this.RegisterButton.UseVisualStyleBackColor = false;
            this.RegisterButton.Click += new System.EventHandler(this.button3_Click);
            // 
            // VerifyPassRegisterTextBox
            // 
            this.VerifyPassRegisterTextBox.Font = new System.Drawing.Font("Corbel", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.VerifyPassRegisterTextBox.Location = new System.Drawing.Point(251, 304);
            this.VerifyPassRegisterTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.VerifyPassRegisterTextBox.Name = "VerifyPassRegisterTextBox";
            this.VerifyPassRegisterTextBox.PasswordChar = '*';
            this.VerifyPassRegisterTextBox.Size = new System.Drawing.Size(419, 36);
            this.VerifyPassRegisterTextBox.TabIndex = 8;
            this.VerifyPassRegisterTextBox.Text = "Password";
            this.VerifyPassRegisterTextBox.Click += new System.EventHandler(this.maskedTextBox3_Click);
            // 
            // RegisterUsernameTextBox
            // 
            this.RegisterUsernameTextBox.Font = new System.Drawing.Font("Calibri", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RegisterUsernameTextBox.Location = new System.Drawing.Point(251, 178);
            this.RegisterUsernameTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.RegisterUsernameTextBox.Name = "RegisterUsernameTextBox";
            this.RegisterUsernameTextBox.Size = new System.Drawing.Size(419, 36);
            this.RegisterUsernameTextBox.TabIndex = 7;
            this.RegisterUsernameTextBox.Text = "Username";
            this.RegisterUsernameTextBox.Click += new System.EventHandler(this.maskedTextBox4_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(136)))), ((int)(((byte)(38)))), ((int)(((byte)(41)))));
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(188, 164);
            this.dataGridView2.Margin = new System.Windows.Forms.Padding(0);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(557, 283);
            this.dataGridView2.TabIndex = 6;
            // 
            // RegisterPassTextBox
            // 
            this.RegisterPassTextBox.Font = new System.Drawing.Font("Calibri", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RegisterPassTextBox.Location = new System.Drawing.Point(251, 240);
            this.RegisterPassTextBox.Margin = new System.Windows.Forms.Padding(4);
            this.RegisterPassTextBox.Name = "RegisterPassTextBox";
            this.RegisterPassTextBox.PasswordChar = '*';
            this.RegisterPassTextBox.Size = new System.Drawing.Size(419, 36);
            this.RegisterPassTextBox.TabIndex = 8;
            this.RegisterPassTextBox.Text = "Password";
            this.RegisterPassTextBox.Click += new System.EventHandler(this.maskedTextBox5_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(199)))), ((int)(((byte)(44)))), ((int)(((byte)(44)))));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(932, 558);
            this.Controls.Add(this.LoginButton);
            this.Controls.Add(this.PasswordLoginTextBox);
            this.Controls.Add(this.UsernameLoginTextBox);
            this.Controls.Add(this.RegisterSwitchButton);
            this.Controls.Add(this.LoginSwitchButton);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.RegisterUsernameTextBox);
            this.Controls.Add(this.RegisterPassTextBox);
            this.Controls.Add(this.VerifyPassRegisterTextBox);
            this.Controls.Add(this.RegisterButton);
            this.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(199)))), ((int)(((byte)(44)))), ((int)(((byte)(44)))));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Log In";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button LoginSwitchButton;
        private System.Windows.Forms.Button RegisterSwitchButton;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.MaskedTextBox UsernameLoginTextBox;
        private System.Windows.Forms.MaskedTextBox PasswordLoginTextBox;
        private System.Windows.Forms.Button LoginButton;
        private System.Windows.Forms.Button RegisterButton;
        private System.Windows.Forms.MaskedTextBox VerifyPassRegisterTextBox;
        private System.Windows.Forms.MaskedTextBox RegisterUsernameTextBox;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.MaskedTextBox RegisterPassTextBox;
    }
}

