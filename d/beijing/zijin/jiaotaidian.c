//Cracked by Roath
// Room: /d/beijing/zijincheng/jiaotaidian.c

inherit ROOM;

void create()
{
	set("short", "��̩��");
	set("long", @LONG
���ǻʺ���Ԫ����ǧ��ʺ�����)�Ƚ������ܳ��صĵط�����
�ﻹ�����йŴ���ʱ�õ�ͭ����©�ʹ������ӣ��������׶�ߡ�����
���Ǵ�Ŷ�ʮ�屦�ĵط�.��ʮ�屦�ǻʵ���ʹ������Ȩ���ı���.��
Щ�������ڸ�����,�����ļ�������.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"longfumen",
  "north" : __DIR__"kunninggong",
  "south" : __DIR__"qianqinggong",
  "east" : __DIR__"jinghemen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
