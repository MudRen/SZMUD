// Code of ShenZhou
// Room: /d/xiangyang/lianwuc.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
���Ǳ�Ӫ�м��һ���յأ���Ӫ�ı�ʿ�Ƿֱ��ж��ڴ˲��������һ�Ӷ�
�Ĺٱ�����������ָ�����������Σ��������ϰ�����С�����˸��Ծ���������
������һЩ�����ˣ����Ǹ�ʿ��������յ�Ͷǹ��İ��ӡ���ʱ���佫��һ��Ѳ
�Ӿ�����
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -2, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"bingying",
  "north" : __DIR__"bingy2",
  "enter" : __DIR__"bingqiku",
  "west" : __DIR__"xiaoshi",
  "south" : __DIR__"bingyi",
]));
        set("objects", ([
               __DIR__"npc/wangjian" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
