//Cracked by Roath
// Room: /d/beijing/zijincheng/jingyunmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
Ϊ�忪�䵥��Ъɽ��.�����˵�¡���Ŷ��Ŷ���.�ǽ�����͢��
����.�峯�涨,��ֵ��󳼻�ʵ��ټ�����Ա��,��ʹ������Ҳ��
��˽�Գ���,ֻ׼�ھ�����,¡�������̨���¶�ʮ����������ּ.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaohuayuan",
  "east" : __DIR__"guang4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
