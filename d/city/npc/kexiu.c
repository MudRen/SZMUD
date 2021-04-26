// Code of ShenZhou
// Jay 5/10/97
// Ryu 11/13/97
//change by wzfeng 99 12
#include <ansi.h>
inherit NPC;
//inherit F_SKILL;

int ask_work(); 
int do_proceed(object who, object ob);

void create()
{
        set_name("�����", ({ "li kexiu", "li" }));
        set_color("$YEL$");
        set("title", "ˮ½�ᶽ");
        set("gender", "����");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "���˾���ǿ�ɣ����˺�ͨ�����ε��㽭ˮ½�ᶽ�����ƶ��������ݵ�����"
        "ͳϽ�����Ӫ����Ͻ���ݵȳ���Э��̫����������ˮʦӪ��\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set("inquiry", ([
                "������" : "������Ů����\n",
                "�л�" : "������Ϸ��лߡ�\n",
                "�ܻ�" : "�Ϸ�Ӳ��ܻߡ�\n",
                "work" : (: ask_work :),
                "����" : (: ask_work :),
        ]));

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("san-sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        map_skill("parry","san-sword");
        map_skill("sword","san-sword");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);

        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object("/clone/armor/junfu")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
}
private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/ymzhengting");
	message_vision("$N�첽���˹�����\n", this_object());
}
void init()
{
        if( environment() != load_object("/d/city/ymzhengting") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
}	


int ask_work()
{
        object *all, *inv, ob, room, me=this_player();
        int i, k, j=0;

        all = users();

                for(i=0; i<sizeof(all); i++)
        {
         if(all[i]->query_temp("mark/Ѳ��") )
                        j++;
        }
        if (j>6){
                command("shake");
                command("say �������ڲ�ȱ���֡�");
                return 1;
        }

        if (me->query_temp("mark/Ѳ��", 1)){
                command("? "+me->query("id"));
                return 1;
        }

        if (me->query("PKS") > 19
        && me->query("combat_exp")/me->query("PKS") < 10000){
                command("hehe "+me->query("id"));
                command("say ���ⲻ����Ͷ������");
                message_vision("$Nһ����Ц�������������ϵĻ���һ��������ͻȻ�ѿ�һ���󶴣�$n����֮�������ȥ��\n", this_object(), me);
                me->apply_condition("city_jail", 50);

                inv = all_inventory(me);
                for(k=0; k<sizeof(inv); k++) {
                if(( inv[k]->query("armor_prop") && inv[k]->query("equipped"))
                || inv[k]->query("no_get"))continue;
                destruct(inv[k]);
                }
                me->move("/d/city/dalao");
                message("vision","ֻ����ƹ����һ����һ��������Ķ��������˽�����\n", environment(me), me);
                return 1;
        }
        
        if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        if (userp(me) && me->query("id") == room->query("winner") ) {
                command("say ���������������������ɵ�������");
                return 1;
        }

        if (me->query("combat_exp") < 50000){
                command("say ������������Сë���������������Ȥ�Ϸ�");
                command("kick "+me->query("id"));
                me->move("/d/city/yamen");
        message("vision","ֻ����ƹ����һ����" +me->query("name") +
                "����������˳�����\n", environment(me), me);
                return 1;
        }

        say("����������Ц�����ã�������ȱ���֣���������������������°ɣ�\n");
        me->set_temp("apply/short",
                    ({ HIR"Ѳ��  "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
        ob=new("/d/city/obj/bounty_list");
        ob->move(me);
        me->set_temp("mark/Ѳ��", 1);
        write("������ڰ��Ϸ��˷����ҳ�һ������ݸ��㡣\n");
        return 1;
}
int accept_kill(object me)
{
        command("say ���˰����д̿ͣ�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        command("say �����������è�������Ҹ��˹��У�");
        return 0;
}

int accept_object(object who, object ob)
{
        object *inv;
        int i;
        if (userp(ob) && ob->query("PKS") >= 50)
                return do_proceed(who, ob);
        else if(userp(ob)) return 0;

        if (!ob->query("money_id")) {
                command("sneer");
                command("say �Ϸ���Ϊ�㽭�ᶽ�����������С��С�ݣ�");
                return 0;
        }
        if (ob->query("money_id") && ob->value() < 10000) {
                command("hmm");
                command("say ������Ϸ��лߡ�");
                return 0;
        }
        if (!who->query_condition("killer")) {
                command("shake " + who->query("id"));
                command("say ������Ѷ���·����ܴ������Ϸ�ͺ��㽻�����Ѱɡ�");
                return 1;
        }
        if (ob->value() < who->query("combat_exp")/10) {
                command("look " + who->query("id"));
                command("say ��İ��ӷ�ͬһ�㣬���Ǯ�������ţ��������²������ġ�");
                return 1;
        }

        command("secret " + who->query("id"));
        command("whisper " + who->query("id")+ " ����¾Ͱ����������ˣ�������߰ɡ�");
        who->apply_condition("killer",0);       
        return 1;
}

int do_proceed(object who, object ob)
{       
        object *inv, obj, gold, room;
        int bonus, i;

        ob->clear_condition();
        ob->set("startroom", "/d/city/dalao");

        inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++) {
                if(( inv[i]->query("armor_prop") && inv[i]->query("equipped"))
                || inv[i]->query("no_get"))continue;
                destruct(inv[i]);
                }

//      if (!present(ob, this_object())) return 1;

        if (!ob->query_temp("armor/shoulder")){
        bonus = ob->query("combat_exp")/10;
        if (bonus > 3000) bonus = 3000;

        if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

        if ( ob->query("id") != room->query("winner") ){
        if(ob->query("PKS") > 99){
        who->add("combat_exp", bonus);
        ob->add("combat_exp", -bonus);
        ob->apply_condition("city_jail", 500);
                }

        else if(ob->query("PKS") > 74){
        who->add("combat_exp", bonus*2/3);
        ob->add("combat_exp", -bonus*2/3);
        ob->apply_condition("city_jail", 300);
                }

        else if(ob->query("PKS") > 49){
        who->add("combat_exp", bonus/2);
        ob->add("comba_exp", -bonus/2);
        ob->apply_condition("city_jail", 200);
                }
        if(ob->query("city_jail") > 4)
                ob->apply_condition("city_jail", 600);
        }
        
        obj=new("/d/city/obj/pblian");
        obj->move(ob);
        obj->set("embedded", 1);
        ob->add("PKS", -1);
        ob->add("city_jail", 1);
        obj->do_embed();
        }

        message_vision("$N�Ը����Ҹ�$n�������ùǣ��Ͻ����Ρ�\n", this_object(), ob);
        call_out("move_ob", 1, ob);

        command("thumb "+who->query("id"));
        gold=new("/clone/money/gold");
        gold->set_amount(10);
        gold->move(who);
        command("say ��������ͽ���ȥЪ�Űɣ�");      
        write("��������һЩ�ƽ�\n");
        command("chat "+ob->query("title")+ob->query("name")+"�ڽ���" 
                + NATURE_D->game_time() +"�������ռࡣ");
        log_file("Jail", sprintf("%s(%s)��%s(%s)�ͽ� city jail on %s.\n",
                  who->query("name"), who->query("id"), ob->query("name"), ob->query("id"), ctime(time())));
        return 1; 
}
void move_ob(object ob)
{
        ob->move("/d/city/dalao");
        message("vision", "ֻ����ƹ����һ����һ��������ļһﱻ���˽�����\n", environment(ob), ob);
}