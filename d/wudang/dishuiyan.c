// Code of ShenZhou
// dishuiyan.c ��ˮ��
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
�������䵱����ǰ�ĵ�ˮ�ܡ�ÿ���꼾����ˮ��������������ϣ�����
ʱ�����ô�����֮��������ˮ���ղ��ϡ���ˮ�ܱ�����˵��������������
���䵱�㳡��
LONG
	);
	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"guangchang",
	]));
	
	setup();
	replace_program(ROOM);
}
