//Cracked by Roath
// Room: /d/beijing/west/fuchengmenjie.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĸ��������֣���ֽ����������ˮ����
��������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա���
��С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ����߿��Կ���������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"fuyoujie2",
  "west" : __DIR__"fuchengmenjie2",
  "east" : __DIR__"beihaiximen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
