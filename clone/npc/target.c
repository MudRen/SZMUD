//Code of Shenzhou
//��̽:target.c
//kissme,2002,2,14

inherit NPC;

string ask_mitan();

string *nm_yg =({
    "��С��","���","��������","������","�ٱ�",
      });

string *id_yg = ({
    "xiao er","huoji","jianghu haoke","tangzi shou","guan bing",
    });

  string *long_yg = ({
    "�����ļ��������һ���Ͳ��Ǻ��ˣ�\n",
    "������ȥ��һ�����ˣ����Ǹ��˵ĸо����ǹֵֹģ�\n",
    "�������׺��쳣�����������˰̣�\n",
    "�����������ֵķ��Σ�����ȴû�����ڣ�\n",
    "�����Źٱ��ķ��Σ�һ���ĺ�����˰̣�\n",
    });

void create()

{
    int i=random(sizeof(nm_yg));
    int rnd=random(100);

    set_name(nm_yg[i],({id_yg[i]}));
    set("long",long_yg[i]);
    set("shen_type",-1);
    set("shen",-100000);

    set("str",20);
    set("int",20);
    set("con",20);
    set("dex",20);

    set("no_refresh",1);

    set("inquiry",([
      "��̽":(:ask_mitan:),
      ]));


    set("chat_chance",10);
    set("chat_msg",({
        (:random_move:),
      }));



    setup();
    carry_object("/clone/armor/beixin")->wear();

     remove_call_out("self_destruct");
    call_out("self_destruct",2500);
}

void init()
{
    object me,*inv;
    int i;

    me=this_object();
    inv=all_inventory(environment(me));


    for(i=0;i<sizeof(inv);i++){
     if(me->query("id")==inv[i]->query("id") || inv[i]->query("yang/ask")>1)
        me->kill_ob(inv[i]);
        }
    call_out("give_tishi",10);

}

string ask_mitan()
{
    object me,ob;

    me=this_player();
    ob=this_object();

     if(ob->query("yang/name")==me->query("id") && me->query("yang/job")){
        message_vision("ֻ��$n��ɫͻȻ���ˣ�\n",me,ob);
    me->add("yang/ask",1);
    if(me->query("yang/ask")>1){
      ob->kill_ob(me);
    me->kill_ob(ob);
    ob->set_leader(me);
      }
    return "����ô֪����\n";
       }
      return "��˵ʲô��\n";
}

void set_status(mixed player_arg){
    object player;
    int exp;

    if(stringp(player_arg)) player = find_player(player_arg);
    else if(objectp(player_arg)) player = player_arg;
    else return;

    if(!objectp(player)) return;
    exp = player->query("combat_exp");

    if(exp < 500000) {
        set("dex",15);
        set("str",15);
       }
    if(exp < 800000){
        set("dex",20);
        set("str",20);
        }
    if(exp <1500000){
        set("str",25);
        set("dex",25);
       }
    if(exp >= 1500000){
        set("dex",30);
        set("str",30);
       }
    carry_object(query("default_weapon"))->wield();
    }

void die()
{
    object ob,me,corpse;

    ob=this_object();
    me=query_temp("last_damage_from");

    message_vision("$N���һ�������ض���!\n",ob);
    me->set("yang/finish",1);

    if(objectp(corpse=CHAR_D->make_corpse(this_object())))
    corpse->move(environment(this_object()));
    destruct(ob);

  if(ob->query("yang/name")==me->query("id") && me->query("yang/job"))
      me->add("yang/finish",1);
    me->delete("yang/ask");
    return;
}

void self_destruct(){
    object me=this_object();
    message("vision",name(1)+"����ææ���뿪�ˡ�\n",environment(me),me);
    destruct(me);
}


void give_tishi(){
    object me=this_player();
    object ob=this_object();

    tell_object(me,ob->query("name")+"����ȥ��ɫ�ܽ���!\n",me,ob);
}
