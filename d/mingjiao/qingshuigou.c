// Code of ShenZhou
// room: /mingjiao/qingshuigou.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
������Ⱥɽ���һ�����������һ��ˮ�����ɿ��Ѿá���ͷһ����
ֻ�ܼ���խխ����ա�����������Ϣ������ʱ�Ų��������ɱ档ż��һȺ
��ȸ�ɹ������ɿ������������֮�������ڶ���ȴ�������˼ž���
LONG );

        set("exits", ([
                "northeast" : __DIR__"daqing",
                "southwest" : __DIR__"longquangu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}