// Code of ShenZhou
// huoji.c �ݵ�ⷼ�

inherit NPC;
inherit F_DEALER;

string ask_me(string);

void create()
{
	set_name("��ⷼ�", ({ "dian huoji", "huoji", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��ⷼ���Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/wudang/obj/mianbing",
		"/d/city/obj/baozi",
		"/d/city/obj/jitui",
		"/d/city/obj/jiudai",
		"/d/village/npc/obj/bottle",
	}));
        set("inquiry", ([
	"�䵱ɽ" : "������꣬���Ż���·�����ϱ㵽�䵱ɽ�ˣ�ɽ�ϵķ羰���ǲ��ܲ��а���\n",
	"�䵱��" : "�ٺ٣��������䵱�ɵ��������治С�����������䵱���������ý�����ֻ��û�˲����ɡ�\n",
        ]) );

	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
	if( base_name(environment(me)) != "/d/wudang/caodian" ) return;
	
	switch( random(2) ) {
		case 0:
			say( "��ⷼ�Ц�����˵������λ" + RANK_D->query_respect(me)
				+ "��·һ�����ˣ�ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��ⷼ��ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(me)
				+ "����������Ҫ��Ҫ�Ұ���������Ҳιһ�£�\n");
			break;
		}

}


