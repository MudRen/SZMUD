// Code of ShenZhou
// Jay 5/7/97
#include <ansi.h>

inherit NPC;

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);

void create()
{
	set_name("л�̿�", ({ "xie yanke", "xie" }));
	set("nickname", "Ħ���ʿ");
	set("long", 
	"���Ǹ����θߴ���ò���ǵ����ߡ�һϮ���������������¹Ĺ����졣\n"+
	"���һ�����룬���Ϸ�����������ɫ��\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 0);
	set("str", 37);
	set("int", 37);
	set("con", 40);
	set("dex", 35);
	
	set("max_qi", 1800);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1500000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
        set_skill("qimen-dunjia", 150);
	set_skill("strike", 150);
	set_skill("hand",150);
	set_skill("finger", 150);
	set_skill("yuxiao-jian", 150);
	set_skill("tianji-xuangong", 150);
	set_skill("luoying-shenjian",150);
	set_skill("luoying-shenfa", 150);
	set_skill("kick", 150);
	set_skill("xuanfeng-saoye", 150);
	set_skill("lanhua-fuxue", 150);
	set_skill("tanzhi-shentong", 150);

	map_skill("force", "tianji-xuangong");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");
	
	prepare_skill("finger", "tanzhi-shentong");

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
}


void init()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        ::init();

        if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
                ob->delete_temp("fee_paid");

        add_action("do_name","ɱ");
	add_action("do_zao","Ҫ");

}

int do_zao(string target)
{
	object me, who, date;
	
	who = this_player();
	me = this_object();

	if (!who->query_temp("ling_paid")) return 0;
	
	command ("say �ã��ϲ�����͸���ժ��");
	date = new(__DIR__"obj/zao");
	date->move(who);
	message_vision("$N������������$nժ��һ������档\n", me, who);
	command("say ���ˣ���������˭Ҳ��Ƿ˭���ˡ�");
	command("jump");
	who->delete_temp("ling_paid");
	return 1;
}

int do_name(string target)
{
        object me, dest, *all;
        int i;
 
        me = this_object();
        all = users();

/*
        if( me->query("sg/spy") )
                return notify_fail("л�̿͹�����Ц����������ɱ���˻�Ҫ�Ϸ������\n");
*/

        if( me->query("waiting_target") )
                return notify_fail("л�̿ͱ�Ǹ��˵������������æ���ģ�������������ɣ�\n");

        if( !this_player()->query_temp("fee_paid") ) 
                return notify_fail("л�̿�˵����Ҫɱ���Լ�ȥɱ���ˣ�\n");

        if( !target || target==" ") 
                return notify_fail("л�̿Ͳ��ͷ���˵������������Ǽһ�����֣��ҿ�û�����������ģ�\n");

        for(i=0; i<sizeof(all); i++) 
        {
                if( target == all[i]->name() || target == all[i]->query("id") )
                        dest = all[i];
	}

        if( !dest )
                return notify_fail("л�̿�һ����Ц�������ڲ�����Ϸ�У����������ɡ�\n");

        if (dest->is_ghost())
                return notify_fail("л�̿ͺܲ����˵�˵�������Ѿ��Ǹ������ˣ��㻹�����Ҹ�ʲô��\n");

/*
        if( dest->query("sg/spy") )
                return notify_fail("л�̿�����һ����˵���������̵������ǲ���\n");
*/

        me->set("waiting_target", dest->query("id"));
        me->set("target_name", target);
        log_file("Playing", sprintf("%s(%s) attempted to let Xie Yanke to kill %s(%s)\n",
                        this_player()->query("name"), getuid(this_player()),
                        dest->query("name"), dest->query("id")) );

        message("vision",
                HIY "л�̿ͺٺٺٵظ�Ц�˼�����˵�����Һ���û�����Բ����塣\n"NOR,
                environment(), me );

//        me->set("pursuer", 1);

        message_vision("$N���˳�ȥ��\n" NOR, me);

        call_out("do_chase", 1, me);

        return 1;
}

int accept_object(object who, object ob)
{

        if (ob->query("id")=="xuantie ling" 
                && !this_object()->query("waiting_target")) 
        {

        if ((int)this_player()->query("age") < 16
        || this_player()->query("combat_exp") < 10000){
                tell_object(who, "л�̿������������һ�ۣ���м��˵����Сë�����㲻������\n");
                return 1;
                }

                tell_object(who, "л�̿͸��˵����㣺"+RANK_D->query_respect(who)+
			"������˰ɣ�Ҫ��Ҫ���棿\n");
                tell_object(who, "����룺Ҫ\n");
                who->set_temp("ling_paid",1);
                return 1;
        }
        else if (ob->query("money_id")) 
        {
                tell_object(who, "л�̿ͺٺ�һЦ��˵����������ô��Ǯ�� �����ҿ�û�����㰡��\n");
                return 1;
        }
	else if(ob->query("id")=="zao") {
		command("say �벻���Ϸ��ݺὭ�����꣬��Ҫ����͡�");
		if (who->query_temp("ling_paid")) {
                	tell_object(who, "л�̿ͳ���������Ҫ��Ȼ�����ɣ��Ұ���ɱ����ҡ�\n");
                	tell_object(who, "����룺ɱ Ŀ����������\n");
                	who->set_temp("fee_paid",1);
			who->delete_temp("ling_paid");
		}
                return 1;
	}

        return 0;
}

int do_chase(object me)
{
        object dest;
        dest = find_player(me->query("waiting_target"));

        if( !objectp(dest) || !environment(dest) )
        {
                call_out("waiting", 0, me);
                return 1;
        }

        me->move(environment(dest));
        message_vision("$N���˹�����\n" NOR, me);
        me->set_leader(dest);
        command("look " + dest->query("id"));

        if ( !environment(me)->query("no_fight"))
        {
                call_out("do_kill", 1, me, dest);
                return 1;
        }
        else
        {
                call_out("waiting", 0, me);
                return 1;
        }

        return 1;
}

int do_kill(object me, object dest)
{

        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
                message_vision(HIR "$N��$n˵���������Ұ�����������������ж������ѣ����Ļ�����������ҵ������κ��£���������Ҫ��ɱ���㡣\n"
                        +RANK_D->query_respect(dest)+"���������ɣ�\n" NOR, me, dest);
                me->set_leader(dest);
                me->kill_ob(dest);
                dest->fight_ob(me);

                call_out("checking", 0,  me); 
        }
        else  
                call_out("waiting", 1, me); 

        return 1;
}

int waiting(object me)
{
        object dest;
        dest = find_player(me->query("waiting_target"));

        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        me->delete("waiting_target");
                        call_out("do_back", 1, me);
                        return 1;
                }else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }else if (living(me) && !environment(dest)->query("no_fight"))
                {
                        call_out("do_chase", 0, me);
                        return 1;
                }
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
        object ob;

        if (me->is_fighting()) 
        {
                call_out("checking", 1, me);
        return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == me->query("target_name") )
        {
                me->delete("waiting_target");
                call_out("do_back", 1, me);
        return 1;
        }

        call_out("waiting", 0, me);
        return 1;
}

int do_back(object me)
{

        me->move("/d/forest/mty1");
        message("vision", "л�̿����˽��������������ϵĳ�����\n"
                "Ц��������ү���ӣ���ֻ������ɱ���ˡ�\n", 
                environment(), me );
        return 1;
}

