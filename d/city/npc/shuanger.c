// Code of ShenZhou
//  ˫��
// kane

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
        set_name("˫��", ({ "shuang er", "shuanger", "shuang"}));
        set("title", "¹��������");
        set("long",
"���ǵ���¹����Τ��ү����λ����֮һ������λ������������������\n"
"�ƽ������һλ�����������䲻��˵������ȴ���ո�ǿ\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 29);

        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);
        set("combat_exp", 50000);
        set("score", 5000);

        set_skill("force", 80);
        set_skill("zixia-gong", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("hunyuan-zhang", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 80);
        set_skill("pishi-poyu", 80);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        set("inquiry", ([
                "�޲�"     : (: ask_me :),
                "�첹"     : (: ask_me :),
                "����"   : (: ask_me :)
        ]));

        setup();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/necklace")->wear();
}

void init()
{
        add_action("do_repair", "repair");
}

string ask_me()
{
        object me = this_player();

        if (query_temp("busy"))
                return "Ӵ����Ǹ�����������æ���ء��������Ժ�\n";
        if (!me->query_temp("allow_repair"))
                return "��λ"+RANK_D->query_respect(me)+"�����ȸ�����������\n";

        me->set_temp("pending/sewing", 1);
        return "��֪����λ"+RANK_D->query_respect(me)+"��Ҫ�Ҳ�(repair)Щʲ�᣿\n"; }

int do_repair(string arg)
{
        object obj,me;
        string file;

        me = this_player();

	if (!arg) return notify_fail("��Ҫ��ʲô������\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("��Ҫ��ʲô������\n");

        if (!obj->query("armor_prop/armor") || obj->query("armor_prop/armor")<1)
                return notify_fail("�ⶫ���ܲ���\n");

        set_temp("busy",1);
        start_busy(2);
        file = resolve_path(this_object()->query("cwd"),arg);
        file = base_name(obj)+".c";

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, obj);

        obj = new(file);
        write("˫������һ�ڳ�����˵�����������ˣ���ȥ�ɣ��´�С�ĵ�Ŷ��\n");
        obj->move(me);
	me->delete_temp("allow_repair");

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{
        command("smile");
	command("say ���Ƕ�л" + RANK_D->query_respect(me) + "���� ��");

        if(ob->query("money_id") && ob->value() >= 500)
                me->set_temp("allow_repair", 1);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
