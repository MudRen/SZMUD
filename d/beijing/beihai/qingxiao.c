//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��������¥Ϊһ��ɽ��֮���㽨����Ъɽ�����ϲ��������ȣ��Ƕ���
�۱���֮����վ�������������Ŀ����������ľ�ɫ��
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "southdown" : __DIR__"yuexin",
                "northdown" : __DIR__"yuegu",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
