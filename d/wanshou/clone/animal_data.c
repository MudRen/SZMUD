// Code of ShenZhou
// animal_data.c
// snowbird, Dec. 1999
// 1.1.1.1

#include <ansi.h>
inherit ITEM;

// provide 2 functions

mixed *GetAnimalData(int i);  // retrieve the data indexed by i
int SetupAnimalData (object obj, int i);  // setup the data after retrieval

//  ��ȸ  ����
//  ����  ����
//  ������ ����
//  ���� ����

// This is a table of animal data

// data1 => ����
// data2 => ����
// data3 => Ұ��
//********************************************************
nosave mixed animal_data1 = ({
/*   0      1        2        3      4      5      6   7   8    9  10*/
/* Index  Name      name1   name2   Race   age    str int con dex  exp */
  ({ 0,   "��ȸ", "ma que", "bird", "����", 3   ,  5,  5,  5, 20,  500,}),
});

nosave mixed animal_long1 = ({
    "һֻߴߴ������������ȥ��С��ȸ��\n",
});
//********************************************************
nosave mixed animal_data2 = ({
/*   0      1        2        3          4      5     6   7    8   9   10*/
/* Index   Name    name1   name2        Race    age  str int  con dex  exp */
  ({ 0,   "����", "lamb", "huang yang", "����", 11  , 20, 10, 20, 20,  2000, }),
});

nosave mixed animal_long2 = ({
    "һֻҰ��������ͷ����س��Ųݡ�\n",
});
//********************************************************
nosave mixed animal_data3 = ({
/*   0      1        2        3        4      5     6   7   8   9   10*/
/* Index   Name    name1   name2     Race    age   str int con dex  exp */
  ({ 0,   "ĸ��", "mu lang","wolf",  "Ұ��", 15  , 30, 10, 20, 20,  5000, }),
  ({ 1,   "�ϻ�", "lao hu", "tiger", "Ұ��", 15  , 40, 15, 30, 40,  500000, }),
  ({ 2,   "����", "bao zi", "bao",   "Ұ��", 15  , 35, 15, 30, 50,  500000, }),
  ({ 3,   "ʨ��", "shi zi", "lion",  "Ұ��", 15   ,50, 15, 30, 50,  500000, }),
});

nosave mixed animal_long3 = ({
    "����һͷ��ɫ��ĸ�ǣ����ú�ɫ���۾������㣬��ʱ�������˵�ս��������\n",
    "����һֻ�����׶��ͻ���ɫ�ʰ�쵣�ʱ��ʱ����צ���ӵأ���Хһ����\n",
    "����һͷ��Ǯ���ӣ�������͹�죬�����۽��������ֵ�������ȥ��\n",
    "����һֻ��ʨ����Ȼ������ʯ�ϣ�����˫Ŀ�����¹��Σ�ȷ��������޵�����֮����\n",
});
//********************************************************


mixed *GetAnimalData(int i)
{
	mixed animal;
	int x, y;

	switch (i/100)
	{
		case 0:
		   y = i;
   	   animal = animal_data1[y];
	      x = sizeof(animal);
	      animal += ({animal_long1[y]});
    		break;
		case 1:
		   y = i-100;
   	   animal = animal_data2[y];
	      x = sizeof(animal);
	      animal += ({animal_long2[y]});
			break;
		case 2:
		   y = i-200;
   	   animal = animal_data3[y];
	      x = sizeof(animal);
	      animal += ({animal_long3[y]});
			break;
	}
    return animal;
}

int SetupAnimalData (object obj, int i)
{
	mixed animal;
	int x;

	// set to default
    obj->set_name("Ұ��", ({"ye shou", "shou"}));
    obj->set("race", "Ұ��");
    obj->set("age", 100);
    obj->set_weight(150000);
    obj->set("long", "һֻ��Ŀ�����Ұ�ޡ�\n");
    obj->set("combat_exp", 1000);
    obj->set("wildness", 5);
    obj->set("loyalty", 5);
    obj->set("auto_follow",1);

	// get the animal data and redo setup
	animal = GetAnimalData(i);
   x = sizeof(animal) - 1;
	obj->set_name(animal[1], ({animal[2], animal[3]}));
	obj->set("race", animal[4]);
	obj->set("age", animal[5]);
	obj->set("str", animal[6]);
	obj->set("int", animal[7]);
	obj->set("con", animal[8]);
	obj->set("dex", animal[9]);
	obj->set("combat_exp", animal[10]);
	obj->set("long", animal[x]);

    return 1;
}

void create()
{
       seteuid(getuid());
}
