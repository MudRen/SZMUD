// Code of ShenZhou
// room: /mingjiao/xinkaiquan.c

inherit ROOM;

void create()
{
        set("short", "�¿�Ȫ");
        set("long", @LONG
���Ǽ����ϱ������ɽ���Ͽ�ȣ��������۵��������죬Ҳ��֪�ж�
����ÿ��ʢ�ĸ�ɽ��ѩ�ܻ������ж��γ���Ϫ�����ﶬ֮��ȴ�ɺ���ˮ��
������ˣ�����û�иߴ���ľ�������ɼ�ͻ������ʯ��
LONG );

        set("exits", ([
                "eastup" : __DIR__"xingzi",
                "west" : __DIR__"yushuquan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}