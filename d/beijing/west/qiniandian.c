//Cracked by Roath
// Room: /d/beijing/west/qiniandian.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�������ܵ�Բ�δ���ɫ�����߶���ȫשľ��
����û�д������ݣ�ȫ����ʮ�˸�ľ������ʮ��������֧�š�
ֵ����������ĸ���������������һ���ļ����в�ʮ��������
����ʮ�����£���Ȧʮ����������ʮ����ʱ������������ʮ��
�������ʮ�ĸ���������ƾ��ɣ�Ԣ�����ء�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"zaichufang1",
  "south" : __DIR__"danbiqiao",
  "northdown" : __DIR__"shibanlu4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
