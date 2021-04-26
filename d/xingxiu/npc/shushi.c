 // CODE MODIFY BY SCATTER
// V 1.0
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void jiaban(object me);
int do_move();
int ask_yirong();
int ask_mianju();

void create()
{
        set_name("������ʿ", ({ "shu shi", "shi", "jianghu shushi"}));
        set("long",  "������ò������ֳ�һ���ȣ�������ʵ���������и����ӵ�֮�硣\n�����ƺ��书��ߡ�");
        set("gender", "����");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",2000);
        set("eff_jing",2000);
        set("eff_qi",2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("env/wimpy", 80);
        set("combat_exp", 800000);
        set("chat_chance_combat", 15);

        set("inquiry", ([
        "����֮��" : (: ask_yirong :),
        "��Ƥ���" : (: ask_mianju :),
        ]));

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("ding-dodge", 200);
        set_skill("ding-force", 200);
        set_skill("ding-unarmed", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("san-sword", 200);
        set_skill("pike", 200);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
        map_skill("pike", "san-sword");

        setup();
        if( clonep() )
        {
                carry_object("/d/city/obj/cloth")->wear();
                carry_object("/d/xingxiu/obj/mianju");
        }

}

void init()
{
        object me=this_player();
        ::init();

        if(random(me->query("kar"))<3){
                call_out("jiaban", 20, me );
        }
        //call_out("do_move", (random(20)+20));
        call_out("dest", 500 );
}


void jiaban(object me){
        if(!objectp(me)) return;
        command("ban "+me->query("id"));
        //command("hehe");
 }

int ask_mianju(){

        object ob;
        object me=this_player();

        if(me->query_temp("gave")){
                if(present("mian ju", this_object())){
                        ob = present("mian ju", this_object());
                        if(ob){
                                ob->move(me);
                        }
                        command("say ����߸��㣬�ú����Űա�");
                        command("hehe");
                        CHANNEL_D->do_channel(me, "rumor", sprintf("��˵%sŪ����һ����Ƥ��ߡ�", me->query("name")));

                } else {
                        command("say ��Ӵ�����治�ɣ�����Ѿ�����ȥ�ˡ�");
                        command("hehe");
                }

                me->delete_temp("gave");
                me->set_temp("canlearn", 1);
                //say("������ʿһ��ȭ���Ҵ��뿪�ˡ�\n");
                //destruct(this_object());
        } else
                say("������ʿ�ٺ�һ����Ц�����ⶫ���������׸��ˣ�\n");

        return 1;
}

int ask_yirong(){

        object me=this_player();


        if(me->query_temp("canlearn", 1) && me->query_temp("gave", 1)){
                write("����������ʿ����ϸ���ͣ��������������������İ��ء�\n");
                me->set_temp("can_ban", 1);
                call_out("dest", 20 );
        } else {
                write("�������룬���û��ǲ�Ҫ���������ˡ�\n");
        }

        return 1;

}

int accept_object(object me, object obj){

        if(obj->query("name")=="��Ԫ��" || obj->query("id")=="jin yuanbao"){
                say("������ʿ�߸����˵ؽ�Ԫ���ŵ��˻��\n");
                me->set_temp("gave", 1);
                call_out("destob", 1, obj);
                return 1;
        } else return 0;


}

void unconcious(){
        say("������ʿһ��������Ӵ�� ת���ܵ���Ӱ���١�\n");
        destruct(this_object());
}

void die(){
        say("������ʿһ��������Ӵ�� ת���ܵ���Ӱ���١�\n");
        destruct(this_object());
}

void destob(object ob){
        destruct(ob);
}

void dest(){
        say("������ʿ�Ҵ�ææ���뿪�ˡ�\n");
        destruct(this_object());
}

int do_move()
{
    object room;
    mapping exits;
    string  *dirs;

    room = environment(this_object());
    exits = room->query("exits");
    dirs = keys(exits);
    command("go "+dirs[random(sizeof(dirs))]);
    call_out("do_move", (random(20)+1));
    return 1;
}
