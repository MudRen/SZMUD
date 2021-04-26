// Code of ShenZhou
// Room: /d/xingxiu/xxh1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
«έ��������һЩ�Ͱ��Ĺ�ľɢ����䣬����������ӡ���ɳ�Ͱ׻�
�����μ��̲�е�ʯͷ�Ͱܲ�֦Ҷ�ϣ������ź��İ�˪��
LONG
        );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/tianlang" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

