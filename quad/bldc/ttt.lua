--dofile("stm32isp.lua")
logEdit:clear()
--isp = STM32ISPDlg()
--isp:exec()

--dofile("serialview.lua")
--x = SerialDlg()
--x:exec()

dofile("bldcviewer.lua")
dlg = BLDCDlg()
dlg:exec()