//Created by Jiuer on Oct 26/2001

inherit ROOM;

void create()
{
	set("short","��ɽ");
	set("long",@LONG
����һƬ��ɽ�±ڣ�ɽʯ���ͣ���ݲ���������żȻ����һ
ֻ�ڻ����������ﵽ�ǲ�ʯ�ĺõط���
LONG
	);
	set("exits",([
		"west" : __DIR__"hill2",
	//  "east" : ,
		]));
	
	set("outdoors", "builder");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}
