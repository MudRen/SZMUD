// Code of ShenZhou
// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���¶�");
        set("long", @LONG
�������������ܶ����ڵ����¶������ڵƻ�ͨ��������һ�ѻ�Ƥ���϶�����
�����������˶����������װ���Ż�Ƥ��¹ͷ�����𣬼�һЩ�ֻ�(zihua)��
���������������ܣ��������еĴ���Ǹ��ֹ�����
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "����Щ�����������ɵ�ʫ�ʺ����Ļ���\n

����������������������������������
����������������������������������
�����������š������¡��ǡ���������
���������������䡡�ޡ���������
�����������ޡ�御��졡�ϡ���������
�����������ȡ���ء��ɡ���������
����������������������������������
����������������������������������
"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiezhang" : 1,
        ]) );

        set("no_clean_up", 0);

	set("cost", 1);
        setup();

}
void init()
{
	add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "ding") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "������" && me->query("family/fa
mily_name") != "������" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ\n", ob, me);

           if ( ob1=present("ding chunqiu", environment(me)) ) {
                message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ����ҵ�������ɱ�ˣ����������ɺ��۸�ô��\n", ob1);
                ob1->kill_ob(me);
           }

           if ( !ob1 ) return 0;

           return 1;
} 
}
