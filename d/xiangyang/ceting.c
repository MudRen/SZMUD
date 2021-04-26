// Code of ShenZhou
// Room: /d/xiangyang/ceting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������˵������ʹƽʱ�Ӽ��������ڣ�����ȴ�����˵�ǹ��ꪡ���������
���Ż�Ƥ��Ƥ��ǽ�Ϲ��Ź�ʸ�������������˴��ɫ��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -3, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bingyi",
  "south" : __DIR__"djtai",
]));

	setup();
	replace_program(ROOM);
}
