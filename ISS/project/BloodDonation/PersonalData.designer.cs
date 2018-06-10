namespace BloodDonation
{
    partial class PersonalData
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
            this.FirstNameTextBox = new System.Windows.Forms.TextBox();
            this.LastNameTextBox = new System.Windows.Forms.TextBox();
            this.phoneNumberTextBox = new System.Windows.Forms.TextBox();
            this.CityComboBox = new System.Windows.Forms.ComboBox();
            this.DoBDatePicker = new System.Windows.Forms.DateTimePicker();
            this.GenderComboBox = new System.Windows.Forms.ComboBox();
            this.AddressTextBox = new System.Windows.Forms.TextBox();
            this.CurrentCityComboBox = new System.Windows.Forms.ComboBox();
            this.CurrentAddressTextBox = new System.Windows.Forms.TextBox();
            this.SavePersonalButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // FirstNameTextBox
            // 
            this.FirstNameTextBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.FirstNameTextBox.Location = new System.Drawing.Point(77, 51);
            this.FirstNameTextBox.Name = "FirstNameTextBox";
            this.FirstNameTextBox.Size = new System.Drawing.Size(176, 30);
            this.FirstNameTextBox.TabIndex = 0;
            this.FirstNameTextBox.Text = "First Name";
            this.FirstNameTextBox.Click += new System.EventHandler(this.FirstNameTextBox_Click);
            // 
            // LastNameTextBox
            // 
            this.LastNameTextBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.LastNameTextBox.Location = new System.Drawing.Point(330, 51);
            this.LastNameTextBox.Name = "LastNameTextBox";
            this.LastNameTextBox.Size = new System.Drawing.Size(176, 30);
            this.LastNameTextBox.TabIndex = 1;
            this.LastNameTextBox.Text = "Last Name";
            this.LastNameTextBox.Click += new System.EventHandler(this.LastNameTextBox_Click);
            // 
            // phoneNumberTextBox
            // 
            this.phoneNumberTextBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.phoneNumberTextBox.Location = new System.Drawing.Point(77, 115);
            this.phoneNumberTextBox.Name = "phoneNumberTextBox";
            this.phoneNumberTextBox.Size = new System.Drawing.Size(244, 30);
            this.phoneNumberTextBox.TabIndex = 4;
            this.phoneNumberTextBox.Text = "Phone Number";
            this.phoneNumberTextBox.Click += new System.EventHandler(this.phoneNumberTextBox_Click);
            // 
            // CityComboBox
            // 
            this.CityComboBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.CityComboBox.FormattingEnabled = true;
            this.CityComboBox.Items.AddRange(this.controller.getCities()); 
            this.CityComboBox.Location = new System.Drawing.Point(77, 241);
            this.CityComboBox.Name = "CityComboBox";
            this.CityComboBox.Size = new System.Drawing.Size(176, 30);
            this.CityComboBox.TabIndex = 5;
            this.CityComboBox.Text = "City";
            // 
            // DoBDatePicker
            // 
            this.DoBDatePicker.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 13.8F);
            this.DoBDatePicker.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.DoBDatePicker.Location = new System.Drawing.Point(77, 177);
            this.DoBDatePicker.Name = "DoBDatePicker";
            this.DoBDatePicker.Size = new System.Drawing.Size(318, 28);
            this.DoBDatePicker.TabIndex = 7;
            // 
            // GenderComboBox
            // 
            this.GenderComboBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.GenderComboBox.FormattingEnabled = true;
            this.GenderComboBox.Items.AddRange(new object[] {
            "Male",
            "Female",
            "Other"});
            this.GenderComboBox.Location = new System.Drawing.Point(448, 175);
            this.GenderComboBox.Name = "GenderComboBox";
            this.GenderComboBox.Size = new System.Drawing.Size(176, 30);
            this.GenderComboBox.TabIndex = 8;
            this.GenderComboBox.Text = "Select Gender";
            // 
            // AddressTextBox
            // 
            this.AddressTextBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.AddressTextBox.Location = new System.Drawing.Point(77, 307);
            this.AddressTextBox.Name = "AddressTextBox";
            this.AddressTextBox.Size = new System.Drawing.Size(494, 30);
            this.AddressTextBox.TabIndex = 9;
            this.AddressTextBox.Text = "Address";
            this.AddressTextBox.Click += new System.EventHandler(this.AddressTextBox_Click);
            // 
            // CurrentCityComboBox
            // 
            this.CurrentCityComboBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.CurrentCityComboBox.FormattingEnabled = true;
            this.CurrentCityComboBox.Items.AddRange(this.controller.getCities());
            this.CurrentCityComboBox.Location = new System.Drawing.Point(77, 367);
            this.CurrentCityComboBox.Name = "CurrentCityComboBox";
            this.CurrentCityComboBox.Size = new System.Drawing.Size(176, 30);
            this.CurrentCityComboBox.TabIndex = 10;
            this.CurrentCityComboBox.Text = "Current City";
            // 
            // CurrentAddressTextBox
            // 
            this.CurrentAddressTextBox.Font = new System.Drawing.Font("Verdana", 11F);
            this.CurrentAddressTextBox.Location = new System.Drawing.Point(77, 427);
            this.CurrentAddressTextBox.Name = "CurrentAddressTextBox";
            this.CurrentAddressTextBox.Size = new System.Drawing.Size(494, 30);
            this.CurrentAddressTextBox.TabIndex = 11;
            this.CurrentAddressTextBox.Text = "Current Address";
            this.CurrentAddressTextBox.Click += new System.EventHandler(this.CurrentAddressTextBox_Click);
            // 
            // SavePersonalButton
            // 
            this.SavePersonalButton.BackColor = System.Drawing.Color.IndianRed;
            this.SavePersonalButton.FlatAppearance.BorderSize = 0;
            this.SavePersonalButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.SavePersonalButton.Font = new System.Drawing.Font("Verdana", 9F);
            this.SavePersonalButton.ForeColor = System.Drawing.SystemColors.Control;
            this.SavePersonalButton.Location = new System.Drawing.Point(592, 488);
            this.SavePersonalButton.Name = "SavePersonalButton";
            this.SavePersonalButton.Size = new System.Drawing.Size(162, 44);
            this.SavePersonalButton.TabIndex = 12;
            this.SavePersonalButton.Text = "Save Data";
            this.SavePersonalButton.UseVisualStyleBackColor = false;
            this.SavePersonalButton.Click += new System.EventHandler(this.SavePersonalButton_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 23);
            this.label1.TabIndex = 0;
            // 
            // PersonalData
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(199)))), ((int)(((byte)(44)))), ((int)(((byte)(44)))));
            this.ClientSize = new System.Drawing.Size(932, 558);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SavePersonalButton);
            this.Controls.Add(this.CurrentAddressTextBox);
            this.Controls.Add(this.CurrentCityComboBox);
            this.Controls.Add(this.AddressTextBox);
            this.Controls.Add(this.GenderComboBox);
            this.Controls.Add(this.DoBDatePicker);
            this.Controls.Add(this.CityComboBox);
            this.Controls.Add(this.phoneNumberTextBox);
            this.Controls.Add(this.LastNameTextBox);
            this.Controls.Add(this.FirstNameTextBox);
            this.Name = "PersonalData";
            this.Text = "PersonalData";
            
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox FirstNameTextBox;
        private System.Windows.Forms.TextBox LastNameTextBox;
        private System.Windows.Forms.TextBox phoneNumberTextBox;
        private System.Windows.Forms.ComboBox CityComboBox;
        private System.Windows.Forms.DateTimePicker DoBDatePicker;
        private System.Windows.Forms.ComboBox GenderComboBox;
        private System.Windows.Forms.TextBox AddressTextBox;
        private System.Windows.Forms.ComboBox CurrentCityComboBox;
        private System.Windows.Forms.TextBox CurrentAddressTextBox;
        private System.Windows.Forms.Button SavePersonalButton;
        private System.Windows.Forms.Label label1;
    }
}