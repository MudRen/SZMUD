//tracy & lnere 12/2001
#include <ansi.h>
inherit NPC;
string ask_me();
int ask_giveup();
int answer();
string ask_start();
   string* room= ({
        "/d/hangzhou/yuhuang"+(1+random(3)),
        "/d/hangzhou/road41",
        "/d/hangzhou/road"+(63+random(4)),
        "/d/hangzhou/road78",
        "/d/hangzhou/lingyin0",
        "/d/hangzhou/suti"+(1+random(7)),
        "/d/hangzhou/kedian",
        "/d/foshan/street"+(1+random(4)),
        "/d/foshan/qzroad"+(1+random(7)),
        "/d/foshan/beidi",
        "/d/quanzhou/zhongxin",
        "/d/quanzhou/xiqiao",
        "/d/quanzhou/yaopu",
        "/d/quanzhou/shanlu"+(1+random(6)),
        "/d/quanzhou/enyuan",
        "/d/huanghe/bank"+(1+random(8)),
        "/d/taishan/daizong",
        "/d/taishan/yitian",
              "/d/city/nandajie"+(1+random(3)),
              "/d/city/dongdajie2"+(1+random(3)),
              "/d/city/yuelao",
              "/d/taishan/yidao",
              "/d/city/zuixianlou",
              "/d/dali/chhill2",
              "/d/city/nanjiao"+(1+random(4)),
              "/d/city/xijiao"+(1+random(4)),
              "/d/dali/dahejie",
              "/d/shaolin/shijie4",
              "/d/wudang/taiziyan",
              "/d/xingxiu/alagou1",
              "/d/qilian/yongchang",
              "/d/hangzhou/hongchun",
              "/d/gaibang/ml1",
              "/d/xingxiu/silk2",
        });
              mapping *miti = ({
                                     ([ "ti":"������������ˮ����һ��","an":"��"]), 
                                     ([ "ti":"����һֱ��һֱ���㡣��һ��","an":"��"]), 
                                             ([ "ti":"���Ӫ���ս��ߡ�  ��һ�֡�","an":"��"]), 
                                             ([ "ti":"���Ĳ��ƣ��п����ԡ���һ�֡�","an":"��"]), 
                                             ([ "ti":"���˺δ�ȥ����һ��","an":"��"]), 
                                             ([ "ti":"���ղ��ܡ���һ�֡�","an":"��"]), 
                                             ([ "ti":"�������ţ����²��㡣��һ�֡�","an":"��"]), 
                                             ([ "ti":"�����ڡ���һ�֡�","an":"��"]), 
                                             ([ "ti":"����ͬ�С���һ�֡�","an":"��"]), 
                                             ([ "ti":"���˲����� ��һ��","an":"��"]), 
                                             ([ "ti":"���ղ�������һ�֡�","an":"��"]), 
                                             ([ "ti":"������һ�ᣬĪ��ֹ�ֲ¡�  ��һ�֡�","an":"��"]), 
                                             ([ "ti":"�˲�����λ����һ�֡�","an":"��"]), 
                                             ([ "ti":"��û�����У���û�е��С�  ��һ�֡�","an":"Ҳ"]), 
                                             ([ "ti":"һ�������ɣ������ֻ�š�  ��һ�֡�","an":"��"]), 
                                             ([ "ti":"�����١���һ�֡�","an":"ֵ"]), 
                                             ([ "ti":"�ٻ���š��³��","an":"����ǧ��"]), 
                                             ([ "ti":"���������ˡ��³��","an":"���˽���"]), 
                                             ([ "ti":"���˻ʵ�����ɡ�  �³��","an":"̰�Ĳ���"]), 
                                             ([ "ti":"��ǧ�Űپ�ʮ�š�  �³��","an":"����һʧ"]), 
                                             ([ "ti":"���Ρ��³��","an":"������ʤ"]), 
                                             ([ "ti":"����үд�ռǡ��³��","an":"����ƪ"]), 
                                             ([ "ti":"�������¿�Ӱ�ӡ�  �³��","an":"�Կ��Դ�"]), 
                                             ([ "ti":"�������ϡ���ֲ�","an":"������"]), 
                                             ([ "ti":"����������ɵ����ţ�","an":"��ɽ"]), 
                                             ([ "ti":"�Ϻ���������С�Ծۼ��������","an":"�ǻ���"]), 
                                             ([ "ti":"�����߹���˭��������","an":"�Ű���"]), 
                                             ([ "ti":"ŷ������ŷ�����ʲô�ˣ�","an":"˽����"]), 
                                             ([ "ti":"�������ܵ������ǣ�","an":"����ͤ"]), 
                                             ([ "ti":"Ѫ����������ڽ�ӹ���Ĳ����","an":"���Ǿ�"]), 
                                      });
void create()
{
        set_name(HIW"ʥ���Ϲ���"NOR, ({ "gong gong", "laoren" }) );
        set("gender", "����");
        set("age", 90);
        set("long","������ʥ������,�ѵ��㲻��ʶ��?�������ְ��ֳ��ĺ���,�´ο�Ҫ��ס����.\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("max_qi", 10000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set_skill("force", 500);
        set_skill("cuff", 500);
        set_skill("whip", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set("chat_chance", 50);
        set("startroom","/d/city/guangchang");
        set("chat_msg", ({
            "ʥ����������һ��ˮ�������˾�˵����ʥ������!��\n",
            "ʥ�����˸�������ʥ����,ףԸ��ң����������!��\n",
            "ʥ���������ĵĶ���˵:�����������?�н�����Ŷ!��\n",
        }) );
        set("inquiry", ([
                "����"     : (: ask_me :),
                "gift"   : (: ask_me :),
                "����"   : (: ask_giveup :),
                "giveup"   : (: ask_giveup :),
                         "start"   : (: ask_start :),
        ]));
        setup();
}
void init()
{
          add_action("do_answer", "answer");
}
mapping query_miti()
{
           return miti[random(sizeof(miti))];
}
string ask_me()
{             mapping miti,an;
             object me = this_player(),ob = this_object();
             if (me->query_condition("gift")>0) return "���һ���������Ұ�!\n";
                  miti = this_object()->query_miti();
                tell_object(me,"ʥ������˵��:�ð�!���ҾͿ�����!\n");
                tell_object(me,MAG""+miti["ti"]+"\n"NOR);
              me->set("gifta",miti["an"]);
                        me->apply_condition("gift",26);
                         return "����,���Ͱ�!!!";
             
}
string ask_start()
{
      if (this_player()->query("id")=="tracy" || this_player()->query("id")=="lnere") {
             
tell_object(users(),HIM"����д�������"+this_object()->query("name")+HIM"���ĵ�Ц������Һã�ʥ�����֣�����ͷ���ص�ǧ�������������ݣ�Ϊ���Ǵ����˾�ϲ�����\n"NOR);
      tell_object(users(),HIW"ֻ������һ������ͷѩ�׵���¹��ʻ��ѩ�˻����ؽ��������ݳǵ�����㳡��\n"NOR);
                             return "merry christmas\n";
      }
                             return "ʲô?\n";
             
}
int do_answer(string arg)
{            object me=this_player(),ob=this_object();
             object obj,liwu,fangjian;
             string ans;
        if (!me->query("gifta")) return 0; 
                        ans=me->query("gifta");
        if (!arg || arg!=ans ) {
                command( "pat "+me->query("id"));
             if( me->query("env/no_accept") ){
              command("why");
              command("say "+me->name()+"��������κζ�����");
                         return 1;
        }
        else {
                tell_object(me,"ʥ����������˵��:û��ϵ,�����Ҳ������!\n");
                tell_object(me,"ʥ�����˴�������ȡ��һö��֥.\n");
                obj = new("/clone/drug/lingzhi");
                obj->move(ob);
                command("give "+me->query("id")+" zhi");
                me->delete("gifta");
                        return 1;
             }
        }
                        command( "wa "+me->query("id"));
                        liwu = new("/u/tracy/liwu");
                        liwu->set("giftp",me->query("id"));
                        fangjian = load_object(room[random(sizeof(room))]);
                        liwu->move(fangjian);
                   tell_object(me,"ʥ������˵:���������ҷŵ���"+fangjian->query("short")+",���ȥ������!\n");
                                      obj = new("/clone/drug/lingzhi");
                                  obj->move(me);
                        me->delete("gifta");
                    return 1;
}
int ask_giveup()
{            object me=this_player(),ob=this_object();
             object obj;
             if (me->query("gifta")) {         
                command( "pat "+me->query("id"));
                       if( me->query("env/no_accept") ){
              command("why");
              command("say "+me->name()+"��������κζ�����");
                         me->delete("gifta");
                         return 1;
                }
                 else {
             
                tell_object(me,"ʥ����������˵��:û��ϵ,�����Ҳ������!\n");
                tell_object(me,"ʥ�����˴�������ȡ��һ���˲ι�.\n");
                obj = new("/clone/drug/renshen_guo");
                obj->move(ob);
                command("give "+me->query("id")+" guo");
                me->delete("gifta");                        
                        return 1;
             }
                       }
                        return 0;
              
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "���Ϲ������ǲ���ܵ�.^&^\n");
        return 0;
}
int accept_kill(object victim)
{
                  object me = this_object();
                  object player = this_player();
                  int flag;
                  command("say " + RANK_D->query_respect(player) + "����ô��ô�ף�����ڵĲ���ɱ�˰���\n");
                  command("benger " + player->query("id") );
             if (player->query("env/immortal"))
                                flag=1;
                  player->delete("env/immortal");
                  player->unconcious();
                 if (flag) player->set("env/immortal",1);
                         command("halt");
                  return 0;
}
