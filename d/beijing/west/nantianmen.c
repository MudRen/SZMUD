//Cracked by Roath
// Room: /d/beijing/west/nantianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������̳���ϴ��ţ���̳����������̳ǽ��̳ǽ�Ϸ�
��Բ����������Բ�ط������ǻʵ�����ȷ�ǵĳ���������
�������ϣ����������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"xiaohutong3",
  "north" : __DIR__"shibanlu5",
  "southwest" : __DIR__"xiaohutong2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
