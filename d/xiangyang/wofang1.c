// Code of ShenZhou
// Room: /d/xiangyang/wofang1.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
�����ǹ����ͻ��ص����ң��ľ���ϰ��������״ɻ�ƿ������
������������̴��ζ�����������䲻������ȴ���ľ����£�������
����ˬ��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huilang1",
]));

	setup();
	replace_program(ROOM);
}
