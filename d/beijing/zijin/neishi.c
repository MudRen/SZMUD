//Cracked by Roath
// Room: /d/beijing/zijincheng/neishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���з���һ�Ŵ󴲣�һ��С����ǽ�Ƿ��ż�ֻ���ӡ����׷���
һֻ��ˮ�ף��Ե�ʮ��ͻأ������ʪ��һ��Ƭ�����ӹص����ϣ�
ÿһ�����춼����ֽ��ס��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhuchu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
