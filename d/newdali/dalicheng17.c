// Code of ShenZhou
// Room: /d/dali/dalicheng17.c

inherit ROOM;

void create()
{
	set("short", "�����ֹ�");
	set("long", @LONG
�����������ƾõ���ʷ���������³�ʫ����ʫ�꡻���䶨ʯ�̡���گ������
»Ȱʯ�̡������¡����������İ������ס�������һ������������������д����
ë�ʻ���ǩд��ֽ��ײ��ϡ��������һ����ѧ��Ϊ�˴�д���ţ����ģ���Լ��
�ȡ�
LONG);
	set("exits", ([
		"south" : __DIR__"dalicheng16",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
