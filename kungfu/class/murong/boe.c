// Code of ShenZhou
// /kungfu/class/murong/boe.c
//Sure /9/17/2000

inherit NPC;
//inherit F_SSERVER;
int auto_perform();

#include <ansi.h>

void create()
{
        set_name("�粨��", ({"feng boe", "feng", "boe"}));
        set("long",  "������Ƽ��ݣ���������Ʋ���룬��󲡳�����\n" );
        set("title", WHT"����һ���" NOR);
        set("gender", "����");
        set("age", 32);
        set("max_qi", 4000);
        set("max_jing", 3500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
	set("combat_exp",3000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("strike", 300);
        set_skill("parry", 300);
        set_skill("blade", 300);
        set_skill("yanxing-dao",300);
        set_skill("murong-shenfa",300);
        set_skill("douzhuan-xingyi",300);
        set_skill("strike",300);
        set_skill("mian-zhang",300);
        set_skill("finger",300);
        set_skill("canhe-zhi",300);
	set_skill("liuhe-dao",300);
	set_skill("literate",220);
	set_skill("xiuluo-dao",300);
	set_skill("xue-dao",300);
	set_skill("liangyi-dao",300);
	set_skill("zixia-gong",300);
	set_skill("linji-zhuang",300);
	set_skill("xiaowuxiang",300);
	set_skill("hunyuan-yiqi",300);
	set_skill("huntian-qigong",300);

        map_skill("dodge", "murong-shenfa");
        map_skill("blade", "liangyi-dao");
        map_skill("finger","canhe-zhi");
        map_skill("parry","liangyi-dao");
	map_skill("force","zixia-gong");

        prepare_skill("finger","canhe-zhi");
	
	create_family("����Ľ��", 19, "����");

	set("chat_chance", 70);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();

        carry_object("/d/murong/obj/qingyi")->wear();
        carry_object("/d/murong/obj/guitou-dao")->wield();

}

int accept_kill(object ob)
{
        command("haha");
        command("say ���������Ҳ����˴���ء����������������ս���ٻغϣ�");
        return 1;
}

int auto_perform()
{
        object me = this_object();
        object ob = me->select_opponent();
        object w, w1, w2;
        string skill, action, spforce;
        int n;

        if ( !me->is_fighting() ) {
                if ( (int)me->query("eff_qi") < (int)me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

        if( !objectp(w1 = present("guitou dao", me))
        &&  !objectp(w2 = present("dahuan dao", me)) ) {
                if( (int)me->query_skill("douzhuan-xingyi") < 300 ) {
                        me->set_skill("douzhuan-xingyi", 300);
                        me->map_skill("force", "douzhuan-xingyi");
                }

                me->reset_action();
                return perform_action("blade.shendao");
        }

        if( !objectp(w1 = present("guitou dao", me))
        &&  !objectp(w2 = present("dahuan dao", me)) ) {
                w2 = new("/d/murong/obj/guitou-dao");
                w2->move(me);
        }

        if( !objectp(w2 = present("dahuan dao", me)) 
        && query("amount") ) {
                add("amount", -1);
                w2 = new("/d/shenlong/obj/dahuan-dao");
                w2->move(me);
        }

        w1 = present("guitou dao", me);
        if( objectp(w1) && objectp(w2) ) n = random(6);
        else if( objectp(w1) && !objectp(w2) ) n = random(5);
        else if( !objectp(w1) && objectp(w2) ) n = 5;
        else {
                me->set_skill("douzhuan-xingyi", 180);
                me->map_skill("force", "douzhuan-xingyi");
                me->reset_action();
                return perform_action("blade.huanying");
        }                

        switch(n) {
        case 0:
                skill = "xue-dao";
                action = "blade.shendao";
                spforce = "xiaowuxiang";
                break;
        case 1:
                skill = "liangyi-dao";
                action = "blade.sanshen";
                spforce = "zixia-gong";
                break;
        case 2:
                skill = "liuhe-dao";
                action = "blade.luanhuan";
                spforce = "huntian-qigong";
                break;
        case 3:
                skill = "yanxing-dao";
                action = "blade.huanying";
                spforce = "linji-zhuang";
                break;
        }

        if( objectp(w = me->query_temp("weapon")) ) {
                if( w == w1 && n < 5 ) {
                        message_vision(HIR"\nͻȻ��$N�ٺٸ�Ц������\n���г��һ��" + w->name() + "˵������������Ҵ�ܣ���׼�ܲ���ѽ����\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "������һ��ֱ��������\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
                }
        } else {
                if( n < 5 ) {
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
                } else {
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "��ʽ���죬ֱ�����Ҫ��������\n"NOR, me);
                }
        }              

        me->map_skill("sword", skill);
        me->map_skill("parry", skill);
        me->map_skill("force", spforce);
        me->reset_action();
        return perform_action(action);
}
