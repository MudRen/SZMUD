//Cracked by Roath
// Room: /d/beijing/west/dongtianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������̳�Ķ����ţ���̳����������̳ǽ��̳ǽ�Ϸ�
��Բ����������Բ�ط������ǻʵ�����ȷ�ǵĳ���������
�������ϣ����������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shibanlu3",
  "east" : "/d/beijing/east/guangqudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
