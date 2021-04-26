// Code of ShenZhou
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include "ansi.h"
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "�����θߴ󣬸߱���Ŀ������ѩ�׶��룬����������\n"
                "������ʹ�����ųơ���������\n");
        set("nickname","����");
        set("title", "����ɽׯׯ��");
        set("gender", "����");
        set("age", 65);

        set("lingshe_count",3);
        set_skill("cuff", 400);
        set_skill("lingshe-quan", 400);
        set_skill("shentuo-zhang", 400);
        set_skill("strike", 360);
        set_skill("dodge", 360);
        set_skill("chanchubu", 360);
        set_skill("parry", 360);
        set_skill("force", 360);
        set_skill("hamagong", 400);
        set_skill("lingshe-zhang",400);
        set_skill("staff",400);
        set_skill("poison",400);
        set_skill("training",360);
        map_skill("strike","hamagong");
        map_skill("staff","lingshe-zhang");
        map_skill("dodge","chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("staff","lingshe-zhang");
        map_skill("force","hamagong");
        prepare_skill("strike","hamagong");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 5500);
        set("qi",5500);
        set("max_jing", 3000);
        set("jing",3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 0);
        set("combat_exp", 3600000);

                  set("attitude", "peaceful");
                  set("shen_type", -1);

                  create_family("����ɽ", 1 , "ׯ��");
        /*        set("chat_chance_combat", 50);
                  set("chat_msg_combat", ({
                         (: auto_perform :),
                  }) );*/
        set("inquiry", ([
                "����" : "����������������ţ��������⡰�����ֹ��������ж���֮�أ�δ���������͡�",
        ]));

        setup();
        carry_object("/d/baituo/obj/lingshezhang")->wield();
        carry_object("/d/baituo/obj/wcloth")->wear();

}

void init()
{
        object ob, me;
        ::init();
        /*
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        */
        
}


void greeting(object me)
{
        int sxds, hand;

        sxds = me->query_skill("shexing-diaoshou",1);
        hand = me->query_skill("hand",1);

        if (me->query("family/family_name") != "����ɽ") {
                me->apply_condition("snake_poison", 
                2 + me->query_condition("snake_poison"));
        }

        if( me->query("family/family_name") == "����ɽ" 
        && !me->query("baituo_updated") ) {
                me->set_skill("cuff", hand);
                me->set_skill("lingshe-quan", sxds);
                me->delete_skill("hand");
                me->delete_skill("shexing-diaoshou");
                me->set("baituo_updated",1);
        }

        if (me->query("enter_shegu")) {
                if ( environment(me) != environment(this_object())) return;

                me->delete("enter_shegu");

                if (me->query("family/family_name") != "����ɽ") {
                        command("hehe "+me->query("id"));
                        command("say "+me->name()+RANK_D->query_rude(me)+"�������ô��߹ȣ�������������ĥ�������ɻ�ˣ������ơ����������ţ�");
                        command("perform shoot "+me->query("id")); //for weapon
                        kill_ob(me);
                }
                else if (me->query("family/family_name") == "����ɽ" 
                && !me->query("baituo/shegu_permit") ) {
                        command("slap "+me->query("id"));
                        command("say ˭���������߹ȵģ�");
                        message_vision(HIR"ŷ������$N�ļ�ͷ���ذ���һ�ƣ���󡹦����ֱ͸���࣬��ʱ���$N�����ֽ���������¡�\n"NOR, me);
                        me->set("neili", 0);
                        me->set("jingli", me->query("jingli")/10);
                        me->set("qi", me->query("qi")/10);
                        me->start_busy(3);
                        command("say ���ͷ������Ǳ������ˡ����������´Σ�");
                }
        }
        return;
}
