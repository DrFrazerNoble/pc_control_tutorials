# Generated by Django 3.2 on 2021-04-08 04:21

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('app', '0002_auto_20210406_1128'),
    ]

    operations = [
        migrations.AlterField(
            model_name='pin',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
