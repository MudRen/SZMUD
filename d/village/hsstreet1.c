// Code of ShenZhou
// hsstreet1
// qfy Oct 15, 97

inherit ROOM;

void create()
{
        set("short", "������·");
        set("long", @LONG
�������·��ǰ���죬·����Щϡϡ�������ӡ�����еĴ������űⵣ�����
���󻺻��߹���·�߲ݴԽ��ܣ��Ͱ��Ĺ�ľ�������µ������š�Ρ���������ɽң
ң������
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
                "west" : "d/village/eexit",
                "east" : __DIR__"hsstreet2",
        ]));
        
        set("objects", ([ 
                "/d/village/npc/dog": 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
