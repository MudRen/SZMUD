// Code of ShenZhou
// liantai.c ʮ����̨ 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "ʮ����̨");
	set("long", @LONG
	�������䵱������ʮ����̨��̨��̨֮����������������̾�������Զ��
��������ڡ�վ����̨��������������ǧҶ����֮�ϣ�ǧ�����ֶ��ڽ��¡�������
�����߰�����Ļ�ɽ��������ˮ�������塢��һ�������۵ס�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"jinding",
	]));
	set("cost", 2);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

