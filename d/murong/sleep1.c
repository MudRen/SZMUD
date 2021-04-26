// Code of ShenZhou
// ROOM /d/murong/sleep1

inherit ROOM;

void create()
{
        set("short", "Ů��Ϣ��");
        set("long", @LONG
����������Ů����Ϣ�ң�Ľ������Ů����һ���ڴ���Ϣ
˯�������ڼ�����ʰ�øɸɾ����Ĵ�����ǽ����һȦ��
LONG );

        set("exits", ([
                "east" : __DIR__"qing5.c",
                ]));

        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}

void init()
{

        add_action("do_get", "get");
}

int do_get(string arg)  
{
        string a,b,c;
        object obj;

        if ( arg && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("�㲻�ܰᶯ��ҵ����塣\n");
                return 1;
        }
        if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 )
                return 0;
        if ( b != "from" ) return 0;
        if ( objectp(obj = present(c, environment(this_player())))
        && obj->is_character() ) {
                write("�㲻�ܴ�˯���˵��������͵������\n");
                return 1;
        }
        return 0;
} 
