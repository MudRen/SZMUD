//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����ɫ����Ĵ���Ϊ�����������֮������ǰ��һ������¯��
��¯���������ƣ��ɼ�����ʢ����м���ͤ��ͤ����������ʯ�������ס�
ʯ�������˵�̾���������Ϊ�ྩ�˾�֮һ��
LONG
	);
	set("cost", 2);
		 
	set("exits", ([
                "northdown" : __DIR__"shiqiao",
                "southwest" : __DIR__"yongansi",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
