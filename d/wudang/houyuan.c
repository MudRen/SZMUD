// Code of ShenZhou
// houyuan.c ��Ժ
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "��Ժ" );
	set("long", @LONG
�����Ǻ�Ժ��������������������һ��Բ�ε��Ŷ�����һ��С·ͨ
����ɽ��̧ͷ�ɼ������쾮�����������ڡ�
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"north" : __DIR__"hd_zoulang",
		"east" : __DIR__"tianjing",
	]));
	
	setup();
	replace_program(ROOM);
}


