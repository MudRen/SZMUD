// Code of Fanren

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

string ask_me();
string ask_all();
 void create() 
{
 set_name(HIW"����"NOR, ({ "old man", "laoren","man" }));
set("long", "����һ��������������ɣ�����ˣ������Ѿ����������Ķ�ͷ,������ʯ�����������š�\n");
set("title", HIW"����"NOR);
  set("gender", "����");
set("age", 200);
 set("attitude", "friendly");
set("shen_type", 1);
set("str", 25);
set("con", 25);
set("int", 25);
set("dex", 25);

set("max_qi", 400); 
set("max_jingli", 400); 
set("jingli", 400);
  set("max_jing", 400); 
set("neili", 400); 
set("max_neili", 400); 
set("combat_exp", 40000); 
set("score", 40000);

                set("inquiry", 
 ([
 "all" : "��֪�������ʲô�أ�(here������������ݾޱ䡢������ɣ������)��\n", 
"here" : "���������ݵ���ʷ����ݡ�\n", 
"��������" : "��ν���ƣ��紵�ƶ�����ֹ��ɢ������Щ�ɡ�\n", 
"���ݾޱ�" : "�����ǵ�Ŭ����Ϣ������ı��Ī�⣬˭��˵�ú��أ�\n", 
"������ɣ" : "ʲô�н���������ɣ�Ͳ��ܽ��������ˡ�\n", 
"����" : "��ֻ�Ǹ����ͣ����ſ��žͲ�ɣǧ���ˡ�\n", 
]));

 setup(); 
 carry_object("/d/kunlun/obj/pao2.c")->wear(); 
}
