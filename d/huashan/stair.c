// Code of ShenZhou
// xiaolu1.c ��ɽ����ʯ��
// qfy 10/8/1997

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ����Ȼ�������ӣ���ͷ�ɼ��Ƚ����ŵ�ʯ�š�����ʯ���Ϲ��ŵ�ȼ
�Ļ�ѣ���ͨ���յ�ʮ��������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"door",
	]));


	set("cost", 0);
	setup();
}


