//tracy & lnere
// gift.c
#include <ansi.h>
#include <room.h>
inherit ITEM;
void create()
{
          switch( random(10) ){
                case 0:
                set_name(HIW"����"NOR, ({ "yu tu","tu"}) );
                set("long", "����һֻ�ɰ���С���ã�ͨ�������񡣺����۾�һգ��գ�Ķ����㡣\n");
                set("unit","ֻ");
                break;
                case 1:
                set_name(MAG"������"NOR, ({ "ziyun ma", "ma" }) );
                set("long", "������������,����Ⱦ�е�����ɫ�ߵ�,����һ�����ɫ�Ļ��Ʒɱ����ڡ�\n�ⶨ��һƥһ��ǧ������ԡ�\n");
                set("unit","ƥ");
                break;
                case 2:
                set_name(HIR"�������"NOR, ({ "zhuge book", "book" }) );
                set("long", "����һ������ʱ����������µ�������ȫ���ǻ۵Ĺ���,����ʧ���Ծá�\n��˵�õ������˻��Ϊ�������\n");
                set("unit","��");
                break;
                case 3:
                set_name(HIC"��������"NOR, ({ "wuzi shu", "shu"}) );
                set("long", "����һ������������Ƴɵ���,���ɫ�İߵ���ʾ���Ȿ�������Զ,\n��ֵ����Ȿ����������������ߡ�\n");
                set("unit","��");
                break;
                case 4:
                set_name(HIR"�����Ʊ�"NOR, ({ "jiu bei","bei" }) );
                set("long", "����һ����Ө��͸�ľƱ�,����װ���˾ơ�\n");
                set("unit","��");
                break;
                case 5:
                set_name(HIR"������"NOR, ({ "qilin zun","zun" }) );
                set("long", "���Ǹ��ܱ߶�����������ɫ���뷽��,ͨ��������,������ʢ�ľ�ɢ��������ĳ�������㡣\nһ����֪�Ǹ��ѵõı��\n");
                set("unit","��");
                break;
                case 6:
                set_name(HIR"������"NOR, ({ "bawang ding","ding" }) );
                   set("long", "����һ��ɫ�ʰ���ɴ�ͭ�Ƴɵ��ĽǷ���,����ʢ��ǧ����������������ȼ������ҡ�\n�ⶦ��˵Ҳ��ǧ���������\n");
                set("unit","��");
                break;
                case 7:
                set_name(HIR"������"NOR, ({ "huoyun shou","shou" }) );
                set("long", "����һͷ�������յ����㶯��,ͨ���ɫ,ֻ��һ�ƻ�����ë�ر���ֱ����ȥ,\n��֫���ϵ���,���ɰױ��,���������Ѫ,����������̤��һ�Ż���֮�ϡ�\n");
                set("unit","ͷ");
                break;
                default:
                set_name(HIR"������"NOR, ({ "huoyun shou", "shou" }) );
                set("long","����һͷ�������յ����㶯��,ͨ���ɫ,ֻ��һ�ƻ�����ë�ر���ֱ����ȥ,\n��֫���ϵ���,���ɰױ��,���������Ѫ,����������̤��һ�Ż���֮�ϡ�\n");
                set("unit","ͷ");    
                break;  
      }
                set("no_get","����������(na)");
                setup();
}
void init()
{
        add_action("do_get", "na");
        add_action("do_ride", "shang");
}
int do_get(string arg)
{ 
        object  ob=this_object();
        object  me=this_player(),gold;
              string id=me->query("id");
         if (!arg) return 0;
                if (ob->query("giftp")!=id) return 0;
          if (arg == "tu" && ob->query("id")=="yu tu" && ob->query("giftp")==id) {
               me->add_temp("apply/dexerity",1);
               message_vision("$N�����������ã�ͻȻ���ֽ�"+ob->query("name")+"������ץס����ɹ��ˣ�\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
         }  
         else if (arg == "shu" && ob->query("id")=="wuzi shu" &&  ob->query("giftp")==id) {
               me->add_temp("apply/intelligence",1);
               message_vision("$N����������,���˼�ҳ,��Ȼ���ǿտհװ׵���һ��,ͻȻ�з촦��һ��С��������$N��ע��:�ô�����,�������\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
         }
         else if (arg == "book" && ob->query("id")=="zhuge book" &&  ob->query("giftp")==id) {
               me->add_temp("apply/intelligence",1);
               message_vision("$N��ȥ���ϵĸ���,С�������ļ���������,���е��ι��ϳ�,��������統�����ְ�ӳ����$N��ǰ��\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
         }
         else if (arg == "bei" && ob->query("id")=="jiu bei" &&  ob->query("giftp")==id) {
               me->add_temp("apply/constitution", 1);     
               message_vision("$N���˱�����,һ��ŨŨ�ľ����˱Ƕ�����$N������ϸ��,һ��ͷ�ȰѾƱ���ľƺȸ��ɾ���\nͻȻ$N����һ��ů���Ե��Ｑ������ȫ��,��������̩ͨů��,����泩��\nԭ����������ɽǧɽ�������ƶ��ɵı�����,�÷����������١�\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
          }
         else if (arg == "zun" && ob->query("id")=="qilin zun" &&  ob->query("giftp")==id) {
               me->add_temp("apply/constitution", 1);     
               message_vision("$N����"+ob->query("name")+"�������ĺ����������ƣ�$Nֻ��һ��ϸϸ�����ߴӺ�ֱ��С������С����ɢ����֫�ٺ���ʹ$N����������\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
          }                 
         else if (arg == "ding" && ob->query("id")=="bawang ding" &&  ob->query("giftp")==id) {
               me->add_temp("apply/strength", 1);     
               message_vision("$N����һ������,���ֽ���ץס����Ķ�Ե,���˵��ͻȻ�������ⶨ����˵ص�"+ob->query("name")+"�Ѿ���$N�߸ߵľ���\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
          }
         else if (arg == "shou" && ob->query("id")=="huoyun shou" &&  ob->query("giftp")==id) {
               me->add_temp("apply/strength", 1);     
               message_vision("$N�Ӻ�����������"+ob->query("name")+",ȴû�ϵ���ͻȻת��,һ��˻��,ǰ��߸�̧��,��$N���˹�����\n$N���а��룺��⣡,��δ�����÷�Ӧ,ֻ��"+ob->query("name")+"����һ���������$N������,\n$Nֻ�����һ����,����,���������ڵ������۳�Ϊһ��������ʧ�����ˡ�\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
                }
            else if (arg == "ma" && ob->query("id")=="ziyun ma" &&  ob->query("giftp")==id) {
               tell_object(me,"�㲻���Խ���������������������(shang)����\n");
               return 1;
                }
                 else return 0;
              if (random(40)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(100);
                gold->move(me);
                 }
                        else if (random(10)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(10);
                gold->move(me);
                 }
                        else if (random(1000)==1) {          
                            new("/clone/drug/pldan")->move(me);
                        }  
                        else if (random(100)==1) {
                            new("/clone/drug/jiuzhuan")->move(me);
                        }
                        else if (random(40)==1) {
                            new("/clone/drug/puti-zi")->move(me);
                        }
                        else if (random(40)==1) {
                            new("/clone/drug/sheli-zi")->move(me);
                        }
               destruct(ob);
               return 1;
  }
int do_ride(string arg)
{ 
               object  ob=this_object(),me=this_player(),gold;
            string id=me->query("id");
         if  (!arg) return 0;
                if (ob->query("giftp")!=id) return 0;
          if (arg == "ma" && ob->query("id")=="ziyun ma" && ob->query("giftp")==id) {
               me->add_temp("apply/dexerity",1);
               message_vision("$N���ĵ��Ƶ����Ĳ���,�����˹�һ����������"+ob->query("name")+"�� \n��������ɱ�,$N���ö��ߺ����ķ���,��˷�����һ��ȫ������������$N������Եı����ж��Ṧ��������...\n",me);
               tell_object(me,"��ϲ�㣬�����ʱ����������1�㣡\n");
                       }
                   else return 0;
              if (random(40)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(100);
                gold->move(me);
                 }
                        else if (random(10)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(10);
                gold->move(me);
                 }
                        else if (random(1000)==1){          
                            new("/clone/drug/pldan")->move(me);
                        }  
                        else if (random(100)==1){
                            new("/clone/drug/jiuzhuan")->move(me);
                        }
                        else if (random(40)==1){
                            new("/clone/drug/puti-zi")->move(me);
                        }
                        else if (random(40)==1){
                            new("/clone/drug/sheli-zi")->move(me);
                        }
               destruct(ob);
               return 1;
        
}