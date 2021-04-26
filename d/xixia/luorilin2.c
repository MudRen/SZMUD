// Code of ShenZhou
// Room: /d/xixia/luorilin2.c

inherit ROOM;

void create()
{
        int i;
        set("short", "������");
        set("long", @LONG
������һƬ��Բ�����ɭ�֣����й�ľ���죬������գ�����������������
�ķ�ľ�����������������ľ������������ϣ����˺ϱ��Ĵ����ȱȽ��ǣ�
һ���������·����ͨ��ǰ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tulu",
  "southwest" : __DIR__"dalu",
]));
        i = random (3);
        switch (i) {
        case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/obj/branch4" : 1,
            "/d/quanzhou/npc/wuya" : 1,
        ]));
        break;
        case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch3" : 1,
            "/d/xingxiu/npc/snake" : 1,
        ]));
        break;
        }
        
        set("cost", 3);
        set("outdoors", "xixia");

        setup();
        replace_program(ROOM);
}
