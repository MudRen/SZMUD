// Code of ShenZhou
// Room: /d/dali/chhill1.c

inherit ROOM;

void create()
{
	set("short", "�軨ɽ");
	set("long", @LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵ����ţ����߲�Զ�ǳ�ǽ��
LONG
	);
	set("objects", ([
		__DIR__"obj/chahua" : 1,

		]));

	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"chhill2.c",
		"westdown" : __DIR__"chhill",
		"east" : __DIR__"chhill3.c",
		"north" : __DIR__"chhill4.c",
		]));

	setup();
}
void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
        object me, ob, weapon;
        me=this_player();

        if (arg=="cha" || arg=="all" || arg=="cha hua") {
                if (!objectp(ob=present("cha", environment(me)))) {
                        tell_object(me, 
"����ûʲô��Ʒ�ֵĲ軨ֵ�����ߡ�\n");
                        return 1;
                }
                if (!objectp(weapon=me->query_temp("weapon"))
                        || weapon->query("id")!="huachu") {
                       tell_object(me, "��û�г��ֵĹ�������ֲ����軨��\n");
                        return 1;
                }
                if (random(2)==1) {
                        
message_vision("$NС��������û�������軨�ĸ���������軨����������\n", me);
                        ob->move(me);
                }
                else {
                        
message_vision("$N����ææ���ڲ軨��һ��С�İѸ��ڶ��ˣ��úõ�һ��軨�����ˡ�\n", me);
                        destruct(ob);
                }
                return 1;
        }
        return 0;
}

