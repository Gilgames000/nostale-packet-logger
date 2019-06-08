#pragma once
#include <msclr/marshal.h>
#include "safequeue.h"


namespace nostalepacketlogger {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for main_form
    /// </summary>
    public ref class main_form : public System::Windows::Forms::Form
    {

    public:
        main_form(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
        main_form(SafeQueue* qSend, SafeQueue* qRecv, void(*lpSendPacket)(LPCSTR), void(*lpReceivePacket)(LPCSTR))
        {
            InitializeComponent();
            this->qSend = qSend;
            this->qRecv = qRecv;
            this->sendPacket = lpSendPacket;
            this->receivePacket = lpReceivePacket;
        }


    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~main_form()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TabControl^  tabView;

    private: System::Windows::Forms::ComboBox^  comboPacketType;
    private: System::Windows::Forms::Button^  btnSubmit;

    private: System::ComponentModel::BackgroundWorker^  sendWorker;
    private: System::ComponentModel::BackgroundWorker^  recvWorker;

    private: System::Windows::Forms::TextBox^  textLogger;
    private: System::Windows::Forms::TextBox^  textPacket;

    private: System::Windows::Forms::TabPage^  tabLogger;
    private: System::Windows::Forms::TabPage^  tabFilters;

    private: System::Windows::Forms::TabPage^  tabAbout;

    private: SafeQueue* qSend;
    private: SafeQueue* qRecv;

    private: void(*sendPacket)(LPCSTR);
    private: void(*receivePacket)(LPCSTR);
    private: System::Windows::Forms::GroupBox^  groupRecvFilters;
    private: System::Windows::Forms::GroupBox^  groupSendFilters;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPacketFilters;
    private: System::Windows::Forms::RadioButton^  radioSendDisable;
    private: System::Windows::Forms::RadioButton^  radioSendWhitelist;
    private: System::Windows::Forms::RadioButton^  radioSendBlacklist;
    private: System::Windows::Forms::Button^  btnSendRemoveFilter;






    private: System::Windows::Forms::Button^  btnSendAddFilter;
    private: System::Windows::Forms::TextBox^  textSendNewFilter;
    private: System::Windows::Forms::ListBox^  listSendFilters;

    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutSendFilterControls;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
    private: System::Windows::Forms::RadioButton^  radioRecvBlacklist;
    private: System::Windows::Forms::RadioButton^  radioRecvDisable;



    private: System::Windows::Forms::RadioButton^  radioRecvWhitelist;

    private: System::Windows::Forms::Button^  btnRecvRemoveFilter;

    private: System::Windows::Forms::Button^  btnRecvAddFilter;
    private: System::Windows::Forms::TextBox^  textRecvNewFilter;
    private: System::Windows::Forms::ListBox^  listRecvFilters;
    private: System::Windows::Forms::CheckBox^  checkSendEnable;

    private: System::Windows::Forms::CheckBox^  checkRecvEnable;

    private: System::Windows::Forms::Button^  btnClearLog;
    private: System::Windows::Forms::GroupBox^  groupAbout;
    private: System::Windows::Forms::LinkLabel^  linkGilgames;

    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::LinkLabel^  linkAtomos;

    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::LinkLabel^  linkNostaleSdk;
    private: System::Windows::Forms::LinkLabel^  linkRepo;


    private: System::Windows::Forms::Label^  label6;





    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->tabView = (gcnew System::Windows::Forms::TabControl());
            this->tabLogger = (gcnew System::Windows::Forms::TabPage());
            this->btnClearLog = (gcnew System::Windows::Forms::Button());
            this->textLogger = (gcnew System::Windows::Forms::TextBox());
            this->comboPacketType = (gcnew System::Windows::Forms::ComboBox());
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->textPacket = (gcnew System::Windows::Forms::TextBox());
            this->tabFilters = (gcnew System::Windows::Forms::TabPage());
            this->tableLayoutPacketFilters = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->groupSendFilters = (gcnew System::Windows::Forms::GroupBox());
            this->checkSendEnable = (gcnew System::Windows::Forms::CheckBox());
            this->tableLayoutSendFilterControls = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->radioSendBlacklist = (gcnew System::Windows::Forms::RadioButton());
            this->radioSendDisable = (gcnew System::Windows::Forms::RadioButton());
            this->radioSendWhitelist = (gcnew System::Windows::Forms::RadioButton());
            this->btnSendRemoveFilter = (gcnew System::Windows::Forms::Button());
            this->btnSendAddFilter = (gcnew System::Windows::Forms::Button());
            this->textSendNewFilter = (gcnew System::Windows::Forms::TextBox());
            this->listSendFilters = (gcnew System::Windows::Forms::ListBox());
            this->groupRecvFilters = (gcnew System::Windows::Forms::GroupBox());
            this->checkRecvEnable = (gcnew System::Windows::Forms::CheckBox());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->radioRecvBlacklist = (gcnew System::Windows::Forms::RadioButton());
            this->radioRecvDisable = (gcnew System::Windows::Forms::RadioButton());
            this->radioRecvWhitelist = (gcnew System::Windows::Forms::RadioButton());
            this->btnRecvRemoveFilter = (gcnew System::Windows::Forms::Button());
            this->btnRecvAddFilter = (gcnew System::Windows::Forms::Button());
            this->textRecvNewFilter = (gcnew System::Windows::Forms::TextBox());
            this->listRecvFilters = (gcnew System::Windows::Forms::ListBox());
            this->tabAbout = (gcnew System::Windows::Forms::TabPage());
            this->groupAbout = (gcnew System::Windows::Forms::GroupBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->linkAtomos = (gcnew System::Windows::Forms::LinkLabel());
            this->linkNostaleSdk = (gcnew System::Windows::Forms::LinkLabel());
            this->linkRepo = (gcnew System::Windows::Forms::LinkLabel());
            this->linkGilgames = (gcnew System::Windows::Forms::LinkLabel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->sendWorker = (gcnew System::ComponentModel::BackgroundWorker());
            this->recvWorker = (gcnew System::ComponentModel::BackgroundWorker());
            this->tabView->SuspendLayout();
            this->tabLogger->SuspendLayout();
            this->tabFilters->SuspendLayout();
            this->tableLayoutPacketFilters->SuspendLayout();
            this->groupSendFilters->SuspendLayout();
            this->tableLayoutSendFilterControls->SuspendLayout();
            this->groupRecvFilters->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->tabAbout->SuspendLayout();
            this->groupAbout->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabView
            // 
            this->tabView->AccessibleDescription = L"";
            this->tabView->AccessibleName = L"";
            this->tabView->Controls->Add(this->tabLogger);
            this->tabView->Controls->Add(this->tabFilters);
            this->tabView->Controls->Add(this->tabAbout);
            this->tabView->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabView->Location = System::Drawing::Point(0, 0);
            this->tabView->Name = L"tabView";
            this->tabView->SelectedIndex = 0;
            this->tabView->Size = System::Drawing::Size(584, 472);
            this->tabView->TabIndex = 0;
            // 
            // tabLogger
            // 
            this->tabLogger->Controls->Add(this->btnClearLog);
            this->tabLogger->Controls->Add(this->textLogger);
            this->tabLogger->Controls->Add(this->comboPacketType);
            this->tabLogger->Controls->Add(this->btnSubmit);
            this->tabLogger->Controls->Add(this->textPacket);
            this->tabLogger->Location = System::Drawing::Point(4, 22);
            this->tabLogger->Name = L"tabLogger";
            this->tabLogger->Padding = System::Windows::Forms::Padding(3);
            this->tabLogger->Size = System::Drawing::Size(576, 446);
            this->tabLogger->TabIndex = 0;
            this->tabLogger->Text = L"Logger";
            this->tabLogger->UseVisualStyleBackColor = true;
            // 
            // btnClearLog
            // 
            this->btnClearLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnClearLog->Location = System::Drawing::Point(513, 419);
            this->btnClearLog->Name = L"btnClearLog";
            this->btnClearLog->Size = System::Drawing::Size(57, 23);
            this->btnClearLog->TabIndex = 5;
            this->btnClearLog->Text = L"Clear log";
            this->btnClearLog->UseVisualStyleBackColor = true;
            this->btnClearLog->Click += gcnew System::EventHandler(this, &main_form::btnClearLog_Click);
            // 
            // textLogger
            // 
            this->textLogger->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textLogger->Location = System::Drawing::Point(7, 6);
            this->textLogger->MaxLength = 999999999;
            this->textLogger->Multiline = true;
            this->textLogger->Name = L"textLogger";
            this->textLogger->ReadOnly = true;
            this->textLogger->ScrollBars = System::Windows::Forms::ScrollBars::Both;
            this->textLogger->Size = System::Drawing::Size(563, 408);
            this->textLogger->TabIndex = 4;
            // 
            // comboPacketType
            // 
            this->comboPacketType->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->comboPacketType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboPacketType->FormattingEnabled = true;
            this->comboPacketType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"SEND", L"RECV" });
            this->comboPacketType->Location = System::Drawing::Point(7, 420);
            this->comboPacketType->MaxDropDownItems = 2;
            this->comboPacketType->MaxLength = 4;
            this->comboPacketType->Name = L"comboPacketType";
            this->comboPacketType->Size = System::Drawing::Size(65, 21);
            this->comboPacketType->TabIndex = 3;
            // 
            // btnSubmit
            // 
            this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnSubmit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnSubmit->Location = System::Drawing::Point(437, 419);
            this->btnSubmit->Name = L"btnSubmit";
            this->btnSubmit->Size = System::Drawing::Size(63, 23);
            this->btnSubmit->TabIndex = 2;
            this->btnSubmit->Text = L"Submit";
            this->btnSubmit->UseVisualStyleBackColor = true;
            this->btnSubmit->Click += gcnew System::EventHandler(this, &main_form::btnSubmit_Click);
            // 
            // textPacket
            // 
            this->textPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textPacket->Location = System::Drawing::Point(78, 421);
            this->textPacket->Name = L"textPacket";
            this->textPacket->Size = System::Drawing::Size(353, 20);
            this->textPacket->TabIndex = 0;
            this->textPacket->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main_form::textPacket_KeyDown);
            // 
            // tabFilters
            // 
            this->tabFilters->Controls->Add(this->tableLayoutPacketFilters);
            this->tabFilters->Location = System::Drawing::Point(4, 22);
            this->tabFilters->Name = L"tabFilters";
            this->tabFilters->Padding = System::Windows::Forms::Padding(3);
            this->tabFilters->Size = System::Drawing::Size(576, 446);
            this->tabFilters->TabIndex = 1;
            this->tabFilters->Text = L"Filters";
            this->tabFilters->UseVisualStyleBackColor = true;
            // 
            // tableLayoutPacketFilters
            // 
            this->tableLayoutPacketFilters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPacketFilters->AutoSize = true;
            this->tableLayoutPacketFilters->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPacketFilters->ColumnCount = 1;
            this->tableLayoutPacketFilters->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPacketFilters->Controls->Add(this->groupSendFilters, 0, 0);
            this->tableLayoutPacketFilters->Controls->Add(this->groupRecvFilters, 0, 1);
            this->tableLayoutPacketFilters->Location = System::Drawing::Point(6, 6);
            this->tableLayoutPacketFilters->Name = L"tableLayoutPacketFilters";
            this->tableLayoutPacketFilters->RowCount = 2;
            this->tableLayoutPacketFilters->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPacketFilters->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPacketFilters->Size = System::Drawing::Size(564, 434);
            this->tableLayoutPacketFilters->TabIndex = 2;
            // 
            // groupSendFilters
            // 
            this->groupSendFilters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupSendFilters->Controls->Add(this->checkSendEnable);
            this->groupSendFilters->Controls->Add(this->tableLayoutSendFilterControls);
            this->groupSendFilters->Controls->Add(this->btnSendRemoveFilter);
            this->groupSendFilters->Controls->Add(this->btnSendAddFilter);
            this->groupSendFilters->Controls->Add(this->textSendNewFilter);
            this->groupSendFilters->Controls->Add(this->listSendFilters);
            this->groupSendFilters->Location = System::Drawing::Point(3, 3);
            this->groupSendFilters->Name = L"groupSendFilters";
            this->groupSendFilters->Size = System::Drawing::Size(558, 211);
            this->groupSendFilters->TabIndex = 0;
            this->groupSendFilters->TabStop = false;
            this->groupSendFilters->Text = L"Send packet filters";
            // 
            // checkSendEnable
            // 
            this->checkSendEnable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->checkSendEnable->AutoSize = true;
            this->checkSendEnable->Checked = true;
            this->checkSendEnable->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkSendEnable->Location = System::Drawing::Point(432, 188);
            this->checkSendEnable->Name = L"checkSendEnable";
            this->checkSendEnable->Size = System::Drawing::Size(120, 17);
            this->checkSendEnable->TabIndex = 8;
            this->checkSendEnable->Text = L"Enable recv logging";
            this->checkSendEnable->UseVisualStyleBackColor = true;
            // 
            // tableLayoutSendFilterControls
            // 
            this->tableLayoutSendFilterControls->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutSendFilterControls->AutoSize = true;
            this->tableLayoutSendFilterControls->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutSendFilterControls->ColumnCount = 1;
            this->tableLayoutSendFilterControls->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutSendFilterControls->Controls->Add(this->radioSendBlacklist, 0, 0);
            this->tableLayoutSendFilterControls->Controls->Add(this->radioSendDisable, 0, 2);
            this->tableLayoutSendFilterControls->Controls->Add(this->radioSendWhitelist, 0, 1);
            this->tableLayoutSendFilterControls->Location = System::Drawing::Point(300, 100);
            this->tableLayoutSendFilterControls->Name = L"tableLayoutSendFilterControls";
            this->tableLayoutSendFilterControls->RowCount = 3;
            this->tableLayoutSendFilterControls->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutSendFilterControls->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutSendFilterControls->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutSendFilterControls->Size = System::Drawing::Size(98, 69);
            this->tableLayoutSendFilterControls->TabIndex = 7;
            // 
            // radioSendBlacklist
            // 
            this->radioSendBlacklist->AutoSize = true;
            this->radioSendBlacklist->Checked = true;
            this->radioSendBlacklist->Location = System::Drawing::Point(3, 3);
            this->radioSendBlacklist->Name = L"radioSendBlacklist";
            this->radioSendBlacklist->Size = System::Drawing::Size(91, 17);
            this->radioSendBlacklist->TabIndex = 4;
            this->radioSendBlacklist->TabStop = true;
            this->radioSendBlacklist->Text = L"Blacklist filters";
            this->radioSendBlacklist->UseVisualStyleBackColor = true;
            // 
            // radioSendDisable
            // 
            this->radioSendDisable->AutoSize = true;
            this->radioSendDisable->Location = System::Drawing::Point(3, 49);
            this->radioSendDisable->Name = L"radioSendDisable";
            this->radioSendDisable->Size = System::Drawing::Size(87, 17);
            this->radioSendDisable->TabIndex = 6;
            this->radioSendDisable->Text = L"Disable filters";
            this->radioSendDisable->UseVisualStyleBackColor = true;
            // 
            // radioSendWhitelist
            // 
            this->radioSendWhitelist->AutoSize = true;
            this->radioSendWhitelist->Location = System::Drawing::Point(3, 26);
            this->radioSendWhitelist->Name = L"radioSendWhitelist";
            this->radioSendWhitelist->Size = System::Drawing::Size(92, 17);
            this->radioSendWhitelist->TabIndex = 5;
            this->radioSendWhitelist->Text = L"Whitelist filters";
            this->radioSendWhitelist->UseVisualStyleBackColor = true;
            // 
            // btnSendRemoveFilter
            // 
            this->btnSendRemoveFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnSendRemoveFilter->Location = System::Drawing::Point(300, 56);
            this->btnSendRemoveFilter->Name = L"btnSendRemoveFilter";
            this->btnSendRemoveFilter->Size = System::Drawing::Size(252, 23);
            this->btnSendRemoveFilter->TabIndex = 3;
            this->btnSendRemoveFilter->Text = L"Remove selected filter";
            this->btnSendRemoveFilter->UseVisualStyleBackColor = true;
            this->btnSendRemoveFilter->Click += gcnew System::EventHandler(this, &main_form::btnSendRemoveFilter_Click);
            // 
            // btnSendAddFilter
            // 
            this->btnSendAddFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnSendAddFilter->Location = System::Drawing::Point(479, 17);
            this->btnSendAddFilter->Name = L"btnSendAddFilter";
            this->btnSendAddFilter->Size = System::Drawing::Size(73, 23);
            this->btnSendAddFilter->TabIndex = 2;
            this->btnSendAddFilter->Text = L"Add";
            this->btnSendAddFilter->UseVisualStyleBackColor = true;
            this->btnSendAddFilter->Click += gcnew System::EventHandler(this, &main_form::btnSendAddFilter_Click);
            // 
            // textSendNewFilter
            // 
            this->textSendNewFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->textSendNewFilter->Location = System::Drawing::Point(300, 19);
            this->textSendNewFilter->Name = L"textSendNewFilter";
            this->textSendNewFilter->Size = System::Drawing::Size(173, 20);
            this->textSendNewFilter->TabIndex = 1;
            this->textSendNewFilter->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main_form::textSendNewFilter_KeyDown);
            // 
            // listSendFilters
            // 
            this->listSendFilters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->listSendFilters->FormattingEnabled = true;
            this->listSendFilters->Location = System::Drawing::Point(6, 19);
            this->listSendFilters->Name = L"listSendFilters";
            this->listSendFilters->Size = System::Drawing::Size(288, 186);
            this->listSendFilters->TabIndex = 0;
            // 
            // groupRecvFilters
            // 
            this->groupRecvFilters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupRecvFilters->Controls->Add(this->checkRecvEnable);
            this->groupRecvFilters->Controls->Add(this->tableLayoutPanel1);
            this->groupRecvFilters->Controls->Add(this->btnRecvRemoveFilter);
            this->groupRecvFilters->Controls->Add(this->btnRecvAddFilter);
            this->groupRecvFilters->Controls->Add(this->textRecvNewFilter);
            this->groupRecvFilters->Controls->Add(this->listRecvFilters);
            this->groupRecvFilters->Location = System::Drawing::Point(3, 220);
            this->groupRecvFilters->Name = L"groupRecvFilters";
            this->groupRecvFilters->Size = System::Drawing::Size(558, 211);
            this->groupRecvFilters->TabIndex = 1;
            this->groupRecvFilters->TabStop = false;
            this->groupRecvFilters->Text = L"Recv packet filters";
            // 
            // checkRecvEnable
            // 
            this->checkRecvEnable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->checkRecvEnable->AutoSize = true;
            this->checkRecvEnable->Checked = true;
            this->checkRecvEnable->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkRecvEnable->Location = System::Drawing::Point(432, 188);
            this->checkRecvEnable->Name = L"checkRecvEnable";
            this->checkRecvEnable->Size = System::Drawing::Size(120, 17);
            this->checkRecvEnable->TabIndex = 13;
            this->checkRecvEnable->Text = L"Enable recv logging";
            this->checkRecvEnable->UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel1->AutoSize = true;
            this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel1->Controls->Add(this->radioRecvBlacklist, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->radioRecvDisable, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->radioRecvWhitelist, 0, 1);
            this->tableLayoutPanel1->Location = System::Drawing::Point(300, 100);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel1->Size = System::Drawing::Size(98, 69);
            this->tableLayoutPanel1->TabIndex = 12;
            // 
            // radioRecvBlacklist
            // 
            this->radioRecvBlacklist->AutoSize = true;
            this->radioRecvBlacklist->Checked = true;
            this->radioRecvBlacklist->Location = System::Drawing::Point(3, 3);
            this->radioRecvBlacklist->Name = L"radioRecvBlacklist";
            this->radioRecvBlacklist->Size = System::Drawing::Size(91, 17);
            this->radioRecvBlacklist->TabIndex = 4;
            this->radioRecvBlacklist->TabStop = true;
            this->radioRecvBlacklist->Text = L"Blacklist filters";
            this->radioRecvBlacklist->UseVisualStyleBackColor = true;
            // 
            // radioRecvDisable
            // 
            this->radioRecvDisable->AutoSize = true;
            this->radioRecvDisable->Location = System::Drawing::Point(3, 49);
            this->radioRecvDisable->Name = L"radioRecvDisable";
            this->radioRecvDisable->Size = System::Drawing::Size(87, 17);
            this->radioRecvDisable->TabIndex = 6;
            this->radioRecvDisable->Text = L"Disable filters";
            this->radioRecvDisable->UseVisualStyleBackColor = true;
            // 
            // radioRecvWhitelist
            // 
            this->radioRecvWhitelist->AutoSize = true;
            this->radioRecvWhitelist->Location = System::Drawing::Point(3, 26);
            this->radioRecvWhitelist->Name = L"radioRecvWhitelist";
            this->radioRecvWhitelist->Size = System::Drawing::Size(92, 17);
            this->radioRecvWhitelist->TabIndex = 5;
            this->radioRecvWhitelist->Text = L"Whitelist filters";
            this->radioRecvWhitelist->UseVisualStyleBackColor = true;
            // 
            // btnRecvRemoveFilter
            // 
            this->btnRecvRemoveFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnRecvRemoveFilter->Location = System::Drawing::Point(300, 56);
            this->btnRecvRemoveFilter->Name = L"btnRecvRemoveFilter";
            this->btnRecvRemoveFilter->Size = System::Drawing::Size(252, 23);
            this->btnRecvRemoveFilter->TabIndex = 11;
            this->btnRecvRemoveFilter->Text = L"Remove selected filter";
            this->btnRecvRemoveFilter->UseVisualStyleBackColor = true;
            this->btnRecvRemoveFilter->Click += gcnew System::EventHandler(this, &main_form::btnRecvRemoveFilter_Click);
            // 
            // btnRecvAddFilter
            // 
            this->btnRecvAddFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnRecvAddFilter->Location = System::Drawing::Point(479, 17);
            this->btnRecvAddFilter->Name = L"btnRecvAddFilter";
            this->btnRecvAddFilter->Size = System::Drawing::Size(73, 23);
            this->btnRecvAddFilter->TabIndex = 10;
            this->btnRecvAddFilter->Text = L"Add";
            this->btnRecvAddFilter->UseVisualStyleBackColor = true;
            this->btnRecvAddFilter->Click += gcnew System::EventHandler(this, &main_form::btnRecvAddFilter_Click);
            // 
            // textRecvNewFilter
            // 
            this->textRecvNewFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->textRecvNewFilter->Location = System::Drawing::Point(300, 19);
            this->textRecvNewFilter->Name = L"textRecvNewFilter";
            this->textRecvNewFilter->Size = System::Drawing::Size(173, 20);
            this->textRecvNewFilter->TabIndex = 9;
            this->textRecvNewFilter->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main_form::textRecvNewFilter_KeyDown);
            // 
            // listRecvFilters
            // 
            this->listRecvFilters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->listRecvFilters->FormattingEnabled = true;
            this->listRecvFilters->Location = System::Drawing::Point(6, 19);
            this->listRecvFilters->Name = L"listRecvFilters";
            this->listRecvFilters->Size = System::Drawing::Size(288, 186);
            this->listRecvFilters->TabIndex = 8;
            // 
            // tabAbout
            // 
            this->tabAbout->Controls->Add(this->groupAbout);
            this->tabAbout->Location = System::Drawing::Point(4, 22);
            this->tabAbout->Name = L"tabAbout";
            this->tabAbout->Padding = System::Windows::Forms::Padding(3);
            this->tabAbout->Size = System::Drawing::Size(576, 446);
            this->tabAbout->TabIndex = 3;
            this->tabAbout->Text = L"About";
            this->tabAbout->UseVisualStyleBackColor = true;
            // 
            // groupAbout
            // 
            this->groupAbout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupAbout->Controls->Add(this->label6);
            this->groupAbout->Controls->Add(this->label4);
            this->groupAbout->Controls->Add(this->label5);
            this->groupAbout->Controls->Add(this->label3);
            this->groupAbout->Controls->Add(this->label2);
            this->groupAbout->Controls->Add(this->linkAtomos);
            this->groupAbout->Controls->Add(this->linkNostaleSdk);
            this->groupAbout->Controls->Add(this->linkRepo);
            this->groupAbout->Controls->Add(this->linkGilgames);
            this->groupAbout->Controls->Add(this->label1);
            this->groupAbout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groupAbout->Location = System::Drawing::Point(8, 6);
            this->groupAbout->Name = L"groupAbout";
            this->groupAbout->Size = System::Drawing::Size(560, 432);
            this->groupAbout->TabIndex = 0;
            this->groupAbout->TabStop = false;
            // 
            // label6
            // 
            this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(137, 74);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(275, 25);
            this->label6->TabIndex = 4;
            this->label6->Text = L"NosTale Packet Logger v0.2.0";
            // 
            // label4
            // 
            this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(199, 190);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(47, 17);
            this->label4->TabIndex = 3;
            this->label4->Text = L"for his";
            // 
            // label5
            // 
            this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(17, 244);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(182, 17);
            this->label5->TabIndex = 3;
            this->label5->Text = L"Check out the repository on";
            // 
            // label3
            // 
            this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(17, 190);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(116, 17);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Special thanks to";
            // 
            // label2
            // 
            this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(372, 307);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(62, 17);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Made by";
            // 
            // linkAtomos
            // 
            this->linkAtomos->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->linkAtomos->AutoSize = true;
            this->linkAtomos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->linkAtomos->Location = System::Drawing::Point(139, 190);
            this->linkAtomos->Name = L"linkAtomos";
            this->linkAtomos->Size = System::Drawing::Size(54, 17);
            this->linkAtomos->TabIndex = 1;
            this->linkAtomos->TabStop = true;
            this->linkAtomos->Text = L"atom0s";
            this->linkAtomos->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &main_form::linkLabel_LinkClicked);
            // 
            // linkNostaleSdk
            // 
            this->linkNostaleSdk->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->linkNostaleSdk->AutoSize = true;
            this->linkNostaleSdk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->linkNostaleSdk->Location = System::Drawing::Point(252, 190);
            this->linkNostaleSdk->Name = L"linkNostaleSdk";
            this->linkNostaleSdk->Size = System::Drawing::Size(93, 17);
            this->linkNostaleSdk->TabIndex = 1;
            this->linkNostaleSdk->TabStop = true;
            this->linkNostaleSdk->Text = L"NosTale SDK";
            this->linkNostaleSdk->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &main_form::linkLabel_LinkClicked);
            // 
            // linkRepo
            // 
            this->linkRepo->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->linkRepo->AutoSize = true;
            this->linkRepo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->linkRepo->Location = System::Drawing::Point(199, 244);
            this->linkRepo->Name = L"linkRepo";
            this->linkRepo->Size = System::Drawing::Size(50, 17);
            this->linkRepo->TabIndex = 1;
            this->linkRepo->TabStop = true;
            this->linkRepo->Text = L"Github";
            this->linkRepo->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &main_form::linkLabel_LinkClicked);
            // 
            // linkGilgames
            // 
            this->linkGilgames->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->linkGilgames->AutoSize = true;
            this->linkGilgames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->linkGilgames->Location = System::Drawing::Point(440, 307);
            this->linkGilgames->Name = L"linkGilgames";
            this->linkGilgames->Size = System::Drawing::Size(67, 17);
            this->linkGilgames->TabIndex = 1;
            this->linkGilgames->TabStop = true;
            this->linkGilgames->Text = L"Gilgames";
            this->linkGilgames->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &main_form::linkLabel_LinkClicked);
            // 
            // label1
            // 
            this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(17, 122);
            this->label1->MaximumSize = System::Drawing::Size(527, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(526, 34);
            this->label1->TabIndex = 0;
            this->label1->Text = L"A free and open source packet logger for the MMORPG NosTale that works on all Gam"
                L"eforge servers.";
            // 
            // sendWorker
            // 
            this->sendWorker->WorkerSupportsCancellation = true;
            this->sendWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &main_form::sendWorker_DoWork);
            // 
            // recvWorker
            // 
            this->recvWorker->WorkerSupportsCancellation = true;
            this->recvWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &main_form::recvWorker_DoWork);
            // 
            // main_form
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->CausesValidation = false;
            this->ClientSize = System::Drawing::Size(584, 472);
            this->Controls->Add(this->tabView);
            this->MinimumSize = System::Drawing::Size(600, 500);
            this->Name = L"main_form";
            this->ShowIcon = false;
            this->Text = L"NosTale Packet Logger";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &main_form::main_form_FormClosing);
            this->Load += gcnew System::EventHandler(this, &main_form::main_form_Load);
            this->tabView->ResumeLayout(false);
            this->tabLogger->ResumeLayout(false);
            this->tabLogger->PerformLayout();
            this->tabFilters->ResumeLayout(false);
            this->tabFilters->PerformLayout();
            this->tableLayoutPacketFilters->ResumeLayout(false);
            this->groupSendFilters->ResumeLayout(false);
            this->groupSendFilters->PerformLayout();
            this->tableLayoutSendFilterControls->ResumeLayout(false);
            this->tableLayoutSendFilterControls->PerformLayout();
            this->groupRecvFilters->ResumeLayout(false);
            this->groupRecvFilters->PerformLayout();
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->tabAbout->ResumeLayout(false);
            this->groupAbout->ResumeLayout(false);
            this->groupAbout->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void main_form_Load(System::Object^  sender, System::EventArgs^  e) {
        array<String^> ^defaultSendFilters = { "walk", "ncif", "pulse" };
        array<String^> ^defaultRecvFilters = { "stat", "mv", "evtb", "cond", "st", "in", "eff" };

        this->comboPacketType->SelectedIndex = 0;

        this->listSendFilters->Items->AddRange(defaultSendFilters);
        this->listRecvFilters->Items->AddRange(defaultRecvFilters);

        this->sendWorker->RunWorkerAsync();
        this->recvWorker->RunWorkerAsync();
    }
    private: System::Void main_form_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
        this->sendWorker->CancelAsync();
        this->recvWorker->CancelAsync();
    }
    private: System::Void btnSubmit_Click(System::Object^  sender, System::EventArgs^  e) {
        if (!String::IsNullOrWhiteSpace(this->textPacket->Text)) {
            msclr::interop::marshal_context context;
            LPCSTR packet = context.marshal_as<LPCSTR>(this->textPacket->Text);

            if (this->comboPacketType->Text->Equals("SEND")) {
                this->sendPacket(packet);
            }
            else if (this->comboPacketType->Text->Equals("RECV")) {
                this->receivePacket(packet);
            }

            this->textPacket->Clear();
        }
    }
    private: System::Void textPacket_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
        if (e->KeyCode == Keys::Enter && !String::IsNullOrWhiteSpace(this->textPacket->Text)) {
            this->InvokeOnClick(this->btnSubmit, nullptr);
            e->SuppressKeyPress = true;
        }
    }
    private: System::Void textSendNewFilter_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
        if (e->KeyCode == Keys::Enter && !String::IsNullOrWhiteSpace(this->textSendNewFilter->Text)) {
            this->InvokeOnClick(this->btnSendAddFilter, nullptr);
            e->SuppressKeyPress = true;
        }
    }
    private: System::Void textRecvNewFilter_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
        if (e->KeyCode == Keys::Enter && !String::IsNullOrWhiteSpace(this->textRecvNewFilter->Text)) {
            this->InvokeOnClick(this->btnRecvAddFilter, nullptr);
            e->SuppressKeyPress = true;
        }
    }
    private: bool validateSendFilters(String^ packet) {
        if (!this->checkSendEnable->Checked) return false;
        if (!this->radioSendDisable->Checked) {
            bool found = this->listSendFilters->FindStringExact(packet) != ListBox::NoMatches;
            if (this->radioSendBlacklist->Checked) return !found;
            if (this->radioSendWhitelist->Checked) return found;
        }
        return true;
    }
    private: bool validateRecvFilters(String^ packet) {
        if(!this->checkRecvEnable->Checked) return false;
        if (!this->radioRecvDisable->Checked) {
            bool found = this->listRecvFilters->FindStringExact(packet) != ListBox::NoMatches;
            if (this->radioRecvBlacklist->Checked) return !found;
            if (this->radioRecvWhitelist->Checked) return found;
        }
        return true;
    }
    private: LPSTR getPacketType(LPSTR packet) {
        LPSTR packetType = (LPSTR)malloc(strlen(packet) + 1);
        LPSTR tmp = packetType;
        while (*packet && *packet != '\n' && *packet != ' ') {
            *tmp = *packet;
            tmp++;
            packet++;
        }
        *tmp = '\0';
        return packetType;
    }
    private: System::Void sendWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
        while (!this->sendWorker->CancellationPending) {
            if (!qSend->empty()) {
                LPSTR packet = this->qSend->front();
                LPSTR packetType = getPacketType(packet);
                if (validateSendFilters(gcnew String(packetType))) {
                    String^ logPacket = "[SEND]: " + gcnew String(packet) + Environment::NewLine;
                    this->textLogger->AppendText(logPacket);
                }
                free(packetType);
                qSend->pop();
            }
        }
    }
    private: System::Void recvWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
        while (!this->recvWorker->CancellationPending) {
            if (!qRecv->empty()) {
                LPSTR packet = this->qRecv->front();
                LPSTR packetType = getPacketType(packet);
                if (validateRecvFilters(gcnew String(packetType))) {
                    String^ logPacket = "[RECV]: " + gcnew String(packet) + Environment::NewLine;
                    this->textLogger->AppendText(logPacket);
                }
                free(packetType);
                qRecv->pop();
            }
        }
    }
    private: System::Void btnSendAddFilter_Click(System::Object^  sender, System::EventArgs^  e) {
        if (!String::IsNullOrWhiteSpace(textSendNewFilter->Text)) {
            this->listSendFilters->Items->Add(textSendNewFilter->Text);
            this->textSendNewFilter->Clear();
        }
    }
    private: System::Void btnRecvAddFilter_Click(System::Object^  sender, System::EventArgs^  e) {
        if (!String::IsNullOrWhiteSpace(textRecvNewFilter->Text)) {
            this->listRecvFilters->Items->Add(textRecvNewFilter->Text);
            this->textRecvNewFilter->Clear();
        }
    }
    private: System::Void btnSendRemoveFilter_Click(System::Object^  sender, System::EventArgs^  e) {
        Object^ selectedFilter = this->listSendFilters->SelectedItem;
        this->listSendFilters->Items->Remove(selectedFilter);
    }
    private: System::Void btnRecvRemoveFilter_Click(System::Object^  sender, System::EventArgs^  e) {
        Object^ selectedFilter = this->listRecvFilters->SelectedItem;
        this->listRecvFilters->Items->Remove(selectedFilter);
    }
    private: System::Void btnClearLog_Click(System::Object^  sender, System::EventArgs^  e) {
        this->textLogger->Clear();
    }
    private: System::Void linkLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
        String^ link;

        if (sender == this->linkAtomos) link = gcnew String("https://github.com/atom0s");
        if (sender == this->linkNostaleSdk) link = gcnew String("http://atom0s.com/forums/viewtopic.php?f=21&t=151");
        if (sender == this->linkRepo) link = gcnew String("https://github.com/gilgames000/nostale-packet-logger");
        if (sender == this->linkGilgames) link = gcnew String("https://github.com/gilgames000");

        try
        {
            System::Diagnostics::Process::Start(link);
        }
        catch (Exception^)
        {
            MessageBox::Show("Unable to open the link that was clicked.");
        }
    }
};
}
