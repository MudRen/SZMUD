//Cracked by Roath
// Room: /d/beijing/zijincheng/sikongchu.c

inherit ROOM;

void create()
{
	set("short", "��״�");
	set("long", @LONG
          һ�����ݣ�ֻ���������ƣ���������ӰӰԼԼ
          ��һ������ͷ����ʿ�����Ʈ�ݣ����Ǵ�
          ʥ�˿��ӡ��˴�Ϊ�ʵ�����ʥ��ʦ����֮�أ�
          Ҳ�����¶����˵�ʥ�ء�(����)
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shangshufang",
  "north" : __DIR__"yuyaofang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
