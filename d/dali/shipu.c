// Code of ShenZhou
// Room: /d/newdali/shipu.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ض���һɽʯ������Ȼ�Ļ��ƶ��������£��Ǳ��Ǵ��������Ĵ���ʯ��
�ô���ʯ�е�ˮī��ʯ�����Ļ�����������̶ȣ�ʹ��̾����ֹ������ʱ������
����̽��嶼���Դ���ʯ���ҾӰ��衣ʯ������ͷ�üã��ô���ĥ֮�������ڶ���
һ��������ͷ���Ű��ӣ���������С����ָ�����»�ơ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road8",
]));
	set("no_clean_up", 0);
	set("cost", 1);
set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shijiang" : 1,
]));

	setup();
	replace_program(ROOM);
}
