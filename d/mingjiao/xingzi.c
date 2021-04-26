// Code of ShenZhou
// room: /mingjiao/xingzi.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
���Ͻ����������겻���Ļ�ѩ��������ҫ֮�£�ʮ�ִ��ۡ�ǿ�紵����
�Ѿ����к��⡣��֪Ϊ�Σ��㿪ʼ�е���Щ�Ļ�������ͷ��Ŀѣ��ÿ�߼�
���Ͳ��ò�ͣ������Ϣ����Χ�Ѿ�û����ľ�����¶���һЩ����������С
�ݡ�
LONG );

        set("exits", ([
                "southdown" : __DIR__"longquangu",
                "westdown" : __DIR__"xinkaiquan",
                "northup" : __DIR__"badake",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}