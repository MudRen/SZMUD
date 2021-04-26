// Code of ShenZhou
// zhaixing.c ժ����
// Ryu. 1997.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xingxiu/auto_perform.h"
string ask_me();
int ask_dan();
int auto_perform();
void create()
{
        set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
        set("nickname", "�����ɴ�ʦ��");
        set("long", 
                "�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
                "�������������۹���͸��һ˿����֮���������\n"
                "��ʦ��������ģ��书ȴ����ߵġ�\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
        set("combat_exp", 500000);
        set("score", 40000);

        set_skill("force", 140);
        set_skill("huagong-dafa", 140);
        set_skill("dodge", 140);
        set_skill("zhaixinggong", 140);
        set_skill("strike", 140);
        set_skill("poison", 140);
        set_skill("chousui-zhang", 140);
        set_skill("feixing-shu", 140);
        set_skill("parry", 140);
        set_skill("claw", 140);
        set_skill("sanyin-zhua", 140);
        set_skill("staff", 140);
        set_skill("tianshan-zhang", 140);
        set_skill("literate", 100);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("claw", "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("������", 2, "����");

        set("inquiry", ([
                "��ɽ����" : (: ask_me :),
                "�ؼ�" : (: ask_me :),
                "����" : (: ask_me :),
                "���ĵ�" : (: ask_dan :),
        ]));

        set("book_count", 1);

        setup();
        carry_object("/d/xingxiu/obj/blzhen");
        carry_object("/d/xingxiu/obj/lianxin");
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

string ask_me()
{
        mapping fam; 
        object ob, *obs, me=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player())+"��δ�ݼ����ɣ���ô����������Ҫ������";

        if (query("book_count") < 1)
                return "��ɽ���������ѱ����˽����ˣ��´��ٸ������Űɡ�";

        add("book_count", -1);

        obs = filter_array(children("/d/xingxiu/obj/throwing_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "��ɽ���������ѱ����˽����ˣ��´��ٸ������Űɡ�";

        ob = new("/d/xingxiu/obj/throwing_book");
        ob->move(this_player());
        return "�������޵İ����������£��Ȿ��������ȥ�ú��ж���������޶�����";
}

void attempt_apprentice(object me)
{
        if( me->query("family/family_name") == "ؤ��"
        && me->query("combat_exp") >= 10000 ) {
                command ("say ����������޽л��ӣ��ҿɲ������㡣");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}
int ask_dan()
{
        if( this_player()->query("family/family_name") != "������"){
        say("ժ���Ӻ���һ��˵���ⶫ���ɲ��Ǹ����õġ�\n");
        return 1;
        }
        if (this_player()->query_temp("marks/˿1")||
        this_player()->query_temp("marks/��1")||
        this_player()->query_temp("marks/�1")||
        this_player()->query_temp("marks/ɳ1")||
        this_player()->query_temp("marks/Ы1")) {
        say("ժ���Ӳ��ͷ���˵�����Ҳ��ǽ���ȥ�Ҷ������𣿶��������͸��㡣\n");
        return 1;
        }
        switch( random(5) )
        {

            case 0:
        say("ժ���ӷ���һ����Ц��˵���������������ߵ������Ҿ͸��㡣\n");
        this_player()->set_temp("marks/��1", 1);
        break;
        case 1:
        say("ժ���ӷ���һ����Ц��˵������������������������Ҿ͸��㡣\n");
        this_player()->set_temp("marks/�1", 1);
        break;
        case 2:
        say("ժ���ӷ���һ����Ц��˵���������������Ы�ӿ������Ҿ͸��㡣\n");
        this_player()->set_temp("marks/Ы1", 1);
        break;
        case 3:
        say("ժ���ӷ���һ����Ц��˵���������������ɳ��������Ҿ͸��㡣\n");
        this_player()->set_temp("marks/ɳ1", 1);
        break;
        case 4:
        say("ժ���ӷ���һ����Ц��˵���������������������˿�����Ҿ͸��㡣\n");
        this_player()->set_temp("marks/˿1", 1);
        break;
        }
        return 1;
}
int accept_object(object who, object ob)
{
        object obj;
        if ((string)ob->query("name")=="����˿" &&
        this_player()->query_temp("marks/˿1" ) ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say �⼸�����ĵ��ú���ĥ���ðɡ�");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/˿1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="���ߵ�" &&
        this_player()->query_temp("marks/��1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=5){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say �⼸�����ĵ��ú���ĥ���ðɡ�");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/��1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="����" &&
        this_player()->query_temp("marks/�1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say �⼸�����ĵ��ú���ĥ���ðɡ�");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/�1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="Ы�ӿ�" &&
        this_player()->query_temp("marks/Ы1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say �⼸�����ĵ��ú���ĥ���ðɡ�");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/Ы1", 0);
        return 1;
        }
    }
        if ((string)ob->query("name")=="ɳ���" &&
        this_player()->query_temp("marks/ɳ1") ) {
        command( "grin");
        this_player()->add("zhai", 1);
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("zhai")>=3){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say �⼸�����ĵ��ú���ȥ�ðɡ�");
        obj = new("/d/xingxiu/obj/lianxin");
        obj->set_amount(5);
        obj->move(this_player());
        this_player()->delete("zhai");
        this_player()->set_temp("marks/ɳ1", 0);
        return 1;
        }
    }
         return 1;
}
void destroy_it(object ob)
{
        if(ob)
        destruct (ob);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob=this_player()) && !this_object()->is_killing(ob)
        && present("shenmu wangding",ob)) {
           message_vision(
           HIY "$Nһ����$n��ŭ�������󱲣���������ʦ�ű����������\n"NOR, this_object(), ob);
        command("follow "+ob->query("id"));
        kill_ob(ob);
        ob->start_busy(1+random(3));
        }
}

