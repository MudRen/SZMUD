//Room: /d/kaifeng/kaifengfu.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "���⸮��");
        set("long", @LONG
������ǿ��⸮���˰칫�µĵط�����ǰ�� (front)����ľ����
������ŵģ������˳ư�����İ������ˡ�����վ���Ʒ粻����������
�ױ��̴ӣ�����ȥ��ʮ�ֱ뺷��
LONG
        );
        set("item_desc", ([
                      "front" : " 
    �������͵�������д���ǡ��������ࡱ��
\n",
]));

        set("exits", ([
                "south":__DIR__"fumen",
                ]));

        set("objects",([
              __DIR__"npc/bao":1,
              __DIR__"npc/wang":1,
              __DIR__"npc/ma":1,
                 ]));
        "clone/board/kff_b.c"->foo();
        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)

{
       if ( me->query_temp("kff/my") == "can" && dir == "south")
              me->delete_temp("kff/my");
        return ::valid_leave(me, dir);
}
